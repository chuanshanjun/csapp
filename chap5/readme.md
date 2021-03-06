# Chap5
## 5.1优化编译器的能力和局限性
* 这种两个指针可能指向同一个内存位置的情况成为**内存别名(memory aliasing)** --343 
* 如果编译器不能确定两个指针是否指向同一个位置，就必须假设什么情况都有可能，这就限制了可能的优化策略。  --p344  
* 包含函数调用的代码可以用一个成为内联函数替换(inline substitution,或者简称"内联(inlining)"的过程优化,此时,将函数调用替换为函数体) --p344

## 5.5 减少过程调用

## 5.6 消除不必要的内存引用

## 5.7 理解现代处理器
* 我们会发现两种下界描述了程序的最大性能。当一系列操作必须按照严格顺序执行时，就会遇到**延迟界限(latency bound)**，因为在下一条指令开始之前，这条指令必须结束。当代码中的数据相关限制了处理器利用指令级并行的能力时，延迟界限能够限制程序性能。**吞吐量界限(throughput bound)**刻画了处理器功能单元的原始计算能力。这个界限是程序性能的终极限制。 --p357
* **超标量(superscalar)**，意思是它可以在每个时钟周期执行多个操作，而且是**乱序的(out-of-order)**，意思就是指令执行顺序不一定要与它们在机器级程序中的顺序一致。和第4章中研究过的**按序(in-order)流水线相比**，乱序处理器需要更大、更复杂的硬件，但是它们能更好地达到更高地指令级并行度。 --p357
* 现代处理器采用了一种称为**分支预测(branch prediction)**的技术，处理器会猜测是否会选择分支，同时还预测分支的目标地址。使用**投机执行(speculative execution)**的技术，处理器会开始取出位于它预测的分支会跳到的地方的指令，并对指令译码，甚至在它确定分支预测是否正确之前就开始执行这些操作。如果过后确定分支预测错误，会将状态重新设置到分支点的状态，并开始取出和执行另一个方向上的指令。标记为**取指控制**的块包括分支预测，以完成确定取哪些指令的任务。 --p358
* 使用投机执行技术对操作求值，但是最终结果不会存放在程序寄存器或数据内存中，直到处理器能确定应该实际执行这些指令。分支操作会被送到EU，不是确定分支该往哪里去，而是确定分支预测是否正确。如果预测错误，EU会丢弃分支点之后计算出来的结果。它还会发信号给分支单元，说预测是错误的，并指出正确的分支目的。在这种情况中，分支单元开始在新的位置取指。 --p359
* 我们可以看出功能单元的这种组合具有同时执行多个同类型操作的潜力。它有4个功能单元可以执行整数操作，2个单元能执行加载操作，2个单元能执行浮点乘法。
* 在一个典型地x86实现中，一条只对寄存器操作地指令，例如
addq %rax, %rdx  
会被转化成一个操作。另一方面，一条包括一个或者多个内存引用的指令，例如  
addq %rax, 8(%rdx)  
会产生多个操作，把内存引用和算术运算分开。这条指令会被译码成三个操作：一个操作从内存中**加载**一个值到处理器中，一个操作将加载进来的值加上寄存器%rax中的值，而一个操作将结果**存回**到内存。这种译码逻辑对指令进行分解，允许任务在一组专门的硬件单元之间进行分割。这些单元可以并行地执行多条指令地不同部分。 --p359
* **延迟界限**给出了任何必须按照严格顺序完成合并运算的函数所需的最小CPE值。根据功能单元产生结果的最大速率，**吞吐界限**给出了CPE的最小界限。例如，因为只有一个整数乘法器，它的发射时间为1个时钟周期，处理器不可能支持每个时钟周期大于1条乘法的速度。另一方面，四个功能单元都可以执行整数加法，处理器就有可能持续每个周期执行4个操作的速率。不幸的是，因为需要从内存读数据，这造成了另一个吞吐量界限。两个加载单元限制了处理器每个时钟周期最多只能读取两个数据值，从而使得吞吐量界限为0.50。 --p362
* 最开始的乘法指令被扩展成一个load操作，从内存读出源操作数，和一个mul操作，执行乘法。 --p363
* 图5-13中的某些操作产生的值不对应于任何寄存器。在右边，用操作间的弧线来表示。load操作从内存读出一个值，然后把它直接传递到mul操作。由于这两个操作是通过对一条vmulsd指令译码产生的，所以这个在两个操作之间传递的中间值没有与之相关的寄存器。cmp操作更新条件码，然后jne操作会测试这些条件码。 --p363
* 正如我们会看到的，循环寄存器之间的操作链决定了限制性能的数据相关。 --p364
* 例如，比较(cmp)和分支(jne)操作不直接影响程序中的数据流。假设指令控制单元预测会选择分支，因此程序会继续循环。比较和分支操作的目的是测试分支条件，如果不选择分支的话，就通知ICU。我们**假设**这个检查能够完成得足够快，不会减慢处理器的执行。 --p364
* 我们可以看到，程序有两条数据相关链，分别对应于操作mul和add对程序值acc和data+i的修改。假设浮点乘法延迟为5个周期，而整数加法延迟为1个周期，可以看到左边的链会成为关键路径，需要5n个周期执行。右边的链只需要n个周期执行，因此，它不会制约程序的性能。  
图5-15说明在执行单精度浮点乘法时，对于combine4，为什么我们获得了等于5个周期延迟界限的CPE。当执行这个函数时，浮点乘法器成为了制约资源。循环中需要的其他操作--控制和测试指针值data+i，以及从内存中读数据———与乘法器**并行地进行**。每次后继的acc值被计算出来，它就反馈回来计算下一个值，不过只有等到5个周期后才能完成 --p365
* 那就是数据流表示中的关键路径提供的只是程序需要周期数的**下界**。还有其他一些因素会限制性能，包括可用的功能单元的数量和任何一步中功能单元之间能够传递数据值的数量。**对于合并运算为整数加法的情况，数据操作足够快，使得其他操作供应数据的速度不够快**。 --p365
* 看上去，延迟界限是基本的限制，决定了我们的合并运算能执行多块。接下来的任务是重新调整操作的结构，**增强指令级并行性**。我们想对程序做变换，使得唯一的限制变成**吞吐量界限**，得到接近于1.00的CPE。 --p365
* 我们看到对于整数加法，CPE有所改进，得到的延迟界限为1.00。会有这样的结果是得益于减少了循环开销操作。相对于计算向量和所需要的加法数量，降低开销操作的数量，此时，整数加法的一个周期的延迟成为了限制性能的因素。 --p367 注：上文说的减少了循环开销操作很可能指的是功能单元之间能够传递数据值的数量。 --p367
* 在此，程序的性能是受运算单元的延迟限制的。不过，正如我们表明的，执行加法和乘法的功能单元是完全流水线化的，这意味着它们可以每个时钟周期开始一个新操作，并且有些操作可以被多个功能单元执行。
硬件具有以更高速率执行乘法和加法的潜力，但是代码不能利用这种能力，即使是使用循环展开也不能，这是因为我们将积累值放在一个单独的变量acc中。在前面的计算完成之前，都不能计算acc的新值。虽然计算acc新值的功能单元能够每个时钟周期开始一个新的操作，但是它只会每L个周期开始一条新操作，这里L是合并操作的延迟。现在我们要考虑打破这种顺序相关，得到比延迟界限更好性能的方法。--p369
* 如果我们的并行度p超过了可用的寄存器数量，那么编译器会诉诸**溢出(spilling)**，将某些临时值存放到内存中，通常是在运行时堆栈上分配空间。... 现代x86-64处理器有16个寄存器，并可以使用16个YMM寄存器来保存浮点数。一旦循环变量的数量超过了可用寄存器的数量，程序就必须在栈上分配一些变量。  --p378
* 在一个使用**投机执行(speculative execution)**的处理器中，处理器会开始执行预测的分支目标处的指令。它会避免修改任何实际的寄存器或内存位置，直到确定了实际的结果。如果预测正确，那么处理器就会“提交”投机执行的指令的结果，把它们存储到寄存器或内存。如果预测错误，处理器必须丢弃掉所有投机执行的结果，在正确的位置，重新开始取指令的过程。这样做会引起预测错误处罚，因为在产生有用的结果之前，必须重新填充指令流水线。 --p378
### 5.11.2 分支预测和预测错误处罚
* 不要过分关心可预测的分支
    * 我们已经看到错误的分支预测的影响可能非常大，但是这并不意味着所有的程序分支都会减缓程序的执行。实际上，现代处理器中的分支预测逻辑非常善于辨别不同的分支指令的有规律的模式和长期的趋势。例如，在合并函数中结束循环的分支通常会被预测为选择分支，因此只在最后一次会导致预测错误处罚。
    * 当从combine2变化到combie3时，我们把函数get_vec_element从函数的内循环中拿了出来，考虑一下我们观察到的结果。
    CPE基本没变，即使这个转变消除了每次迭代中用于检查向量索引是否在界限内的两个条件语句。对这个函数来说，这些检测总是确定索引是在界内的，所以是高度可预测的。
* 书写适合用条件传送实现的代码
    * 翻译成条件传送的基本思想是计算出一个条件表达式或语句两个方向上的值，然后用条件传送选择期望的值。 --p379
    * 对于这些测试，分支预测逻辑会处理得很糟糕。对于本质上无法预测的情况，如果编译器能够产生使用**条件数据传送**而不是使用条件控制转移的代码，可以极大地提高程序性能。这不是C语言程序猿可以直接控制的，但是有些表达条件行为的方法能够更直接地被翻译成条件传送，而不是其他操作。 --p380
* 如图5-11所示，现代处理器有专门的功能单元来执行加载存储操作，这些单元有内部的缓冲区来保存未完成的内存操作请求集合。 --p382
* 5.12.1 加载的性能 
    * 我们看到除了使用SIMD操作时以外，对任何数据类型组合和合并操作来说，CPE从没有到过0.50以下。一个制约示例的CPE的因素是，对于每个被计算的元素，所有的示例都需要从哪从读一个值。对两个加载单元而言，其每个时钟周期只能启动一条加载操作，所以CPE不可能小于0.50。对于每个被计算的元素必须加载k个值的应用，我们不可能获得低于k/2的CPE。
    * 加载操作的地址只依赖于循环索引i，所以加载操作不会成为限制性能的关键路径的一部分。 --p382
    * 通过链表函数测试出，遍历该链表的CPE等于4.00，是由加载操作的延迟决定的。事实上，这个测试结果与文档中参考机的L1级cache的4周期访问时间是一致的，相关内容将在6.4节中讨论。
* 5.12.2 存储的性能
    * **存储(store)**操作，它将一个寄存器值写到内存。
    * 例如，考虑图5-32中所示的函数，它们将一个长度为n的数组dest的元素设置为0。我们测试结果为CPE等于1.00。对于只具有单个存储功能单元的机器，这已经达到了最佳情况。 --p383
    * 与到目前为止我们已经考虑过的其他操作不同，存储操作并不影响任何寄存器值。因此，就其本性来说，一系列存储操作不会产生数据相关。只有加载操作会受存储操作结果的影响，因为只有加载操作能从由存储操作写的那个位置读回值。 --p383
    * **写/读相关(write/read dependency)**--一个内存读的结果依赖于一个最近的内存写。我们的性能测试表明示例B的CPE为7.3。写/读相关导致处理速度下降约6个时钟周期。 --p383
    * 当一个加载操作发生时，它必须检查存储缓冲区中的条目，看有没有地址相匹配。如果有地址相匹配（意味着在写的字节与在读的字节有相同的地址），它就取出相应的条目作为加载操作的结果。 --p385
    * 指令movq %rax, (%rsi)被翻译成两个操作:s_addr指令计算存储操作的地址，在存储缓冲区创建一个条目，并且设置该条目的地址字段。s_data操作设置该条目的数据字段。正如我们会看到的，两个计算是独立执行的，这对程序的性能来说很重要。这使得参考机中不同的功能单元来执行这些操作。--p385
    * s_addr操作的地址计算必须在s_data操作之前。此外，对指令movq (%rdi), %rax译码得到的load操作必须检查所有未完成的存储操作的地址，在这个操作和s_addr操作之间创建一个数据相关。**如果两个地址相同，load操作必须等待直到s_data将它的结果存放到存储缓冲区中，但是如果两个地址不同，两个操作就可以独立地进行。**
* 这个示例说明了一个现象，我们称之为**写/读相关(write/read dependency)**--一个内存读的结果依赖于一个最近的内存写。我们的性能测试表明示例B的CPE为7.3。写/读相关导致处理速度下降约6个时钟周期。在4.5.7节中我们看到，条件传送指令可以被实现为普通指令流水线化处理的一部分。没有必要猜测条件是否满足，因此猜测错误也没有处罚。 --p383
* 当一个加载操作发生时，它必须检查存储缓冲区中的条目，看有没有地址相匹配。如果有地址相匹配（意味着在写的字节与读的字节有相同的地址），它就取出相应的数据条目作为加载操作的结果。--p384
* 这张图中s_data和load操作之间有虚弧线。这个数据相关是有条件的：如果两个地址相同，load操作必须等待直到s_data将它的结果存放到存储缓冲区中，但是如果两个地址不同，两个操作就可以独立地运行。 --p385
