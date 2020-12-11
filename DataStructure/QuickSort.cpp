#include <iostream>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
/**
 * @brief 
 * 
 * @param arr 
 * @param front 数列最前端的指针
 * @param end 数列最尾端的指针
 * @return int 
 */
int Partition(int *arr, int front=0, int end){
    int pivot = arr[end]; 
    int i = front -1; 					// 所有小於pivot的數所形成的數列的「最後位置」常为-1
    for (int j = front; j < end; j++) { // j從front檢查到end-1(因為end是pivot自己)
        if (arr[j] < pivot) { 			// 發現有數比pivot小
            i++; 						// 「所有小於pivot的數所形成的數列」又增加了一名成員
            swap(&arr[i], &arr[j]);
        }								
    }  // 當演算法結束時，所有在a(i)左邊的數，都比pivot小，所有在a(i)右邊的數，都比pivot大
    i++;								// i移动到pivot将来的地方
    swap(&arr[i], &arr[end]); 			// 把pivot搬到序列中间
    return i;
}

/**
 * @brief 
 * 
 * @param arr 
 * @param front 数列首元素的下标
 * @param end 数列尾元素的下标
 */
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
void PrintArray(int *arr, int size){
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    int n = 9;
    int arr[] = {9, 4, 1, 6, 7, 3, 8, 2, 5};
    std::cout << "original:\n";
    PrintArray(arr, n);

    QuickSort(arr, 0, n-1);

    std::cout << "sorted:\n";
    PrintArray(arr, n);
    return 0;
}
