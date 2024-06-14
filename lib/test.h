class Window {
    int value;
    public:
        Window (int v): value(v) {
            this->value = v;
        }

        int test() {
            value++;
            return value;
        }
};