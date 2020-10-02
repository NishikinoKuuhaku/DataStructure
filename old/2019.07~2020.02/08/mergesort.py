def merge(b1, b2)：
# 双指针合并


def mergeSort(a):  # a 是一个没有排好序的数组
    if len(a) == 1:
        return a
    b1 = mergeSort(a[0:len(a) // 2])        # 将数组的前半段排好序得到 b1
    b2 = mergeSort(a[len(a)//2: len(a)])    # 将数组的后半段排好序得到 b2
    c = merge(b1, b2)                       # 将 b1 b2 合在一起得到完整的数组（排好序的）
    return c
