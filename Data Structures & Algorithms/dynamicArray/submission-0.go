type DynamicArray struct {
    data []int
    size int
}

func NewDynamicArray(capacity int) *DynamicArray {
    return &DynamicArray{
        data: make([]int, capacity),
        size: 0,
    }
}

func (da *DynamicArray) Get(i int) int {
    return da.data[i]
}

func (da *DynamicArray) Set(i int, n int) {
    da.data[i] = n
}

func (da *DynamicArray) Pushback(n int) {

    if(cap(da.data) == da.size){
        da.resize()
    }
    da.data[da.size] = n
    da.size++
}

func (da *DynamicArray) Popback() int {
    val := da.data[da.size-1]
    da.size--
    return val
}

func (da *DynamicArray) resize() {
    newData := make([]int, cap(da.data) * 2)
    copy(newData, da.data)
    da.data = newData
}

func (da *DynamicArray) GetSize() int {
    return da.size
}

func (da *DynamicArray) GetCapacity() int {
    return cap(da.data)
}
