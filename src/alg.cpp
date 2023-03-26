// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = i + 1; j < len; j++) {
        if (arr[i] + arr[j] == value) {
            search = search + 1;
            }
        }
    }
    return search;
}
int countPairs2(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
      for (int j = len - 1; i < j; j--) {
        if (arr[i] + arr[j] == value) {
            search = search + 1;
            }
        }
    }
    return search;
}
int countPairs3(int* arr, int len, int value) {
    int search = 0;
    for (int i = 0; i < len - 1; i++) {
        int first = i, second = len;
        while (first < second - 1) {
            int ctr = (first + second) / 2;
            if (arr[i] + arr[ctr] == value) {
                search = search + 1;
                int nCtr = ctr + 1;
                while (arr[i] + arr[nCtr] == value && nCtr < second) {
                    search = search + 1;
                    nCtr = nCtr + 1;
                }
                nCtr = ctr - 1;
                while (arr[i] + arr[nCtr] == value && nCtr > first) {
                    search = search + 1;
                    nCtr = nCtr - 1;
                }
                break;
            }
            if (arr[i] + arr[ctr] > value) {
                second = ctr;
            } else {
                first = ctr;
            }
        }
    }
    return search;
}
