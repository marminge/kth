int main(void) {
    int i = 5;
    int *p = &i;
    int *q = &i;

    p = *&q;
    p = q;
    *p = *q;


    /*
    Legal assignments
    p = *&q;
    p = q;
    *p = *q;
    */
    return 0;
}
