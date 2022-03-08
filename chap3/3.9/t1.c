struct rect {
    long llx;
    long long lly;
    unsigned long width;
    unsigned long height;
    unsigned color;
};

long area(struct rect *rp) {
    return (*rp).width * (*rp).height;
}

void rotate_left(struct rect *rp) {
    /* Exchange width and height */
    long t = rp->height;
    rp->height = rp->width;
    rp->width = t;
    rp->llx -= t;
}

void main() {
    // init method 1
    struct rect r1;
    r1.llx = r1.lly = 0;
    r1.color = 0xFF00FF;
    r1.width = 10;
    r1.height = 20;

    // init method 2
    struct rect r2 = {0, 0, 10, 20, 0xFF00FF};

    area(&r1);
}