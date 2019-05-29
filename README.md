# Vector - Mantas Kraujelis

## Funkcionalumas
```c++
void assign(size_t val, T data) {
        vsize_ = val;
        cap_ = val;
        delete[] arr_;
        T * other = new T[vsize_];
        std::fill_n(other, vsize_, data);
        arr_ = other;
    }
```
```c++
void pop_back()
    {
        vsize_ = vsize_ - 1;
        T *laikinas = new T[vsize_];
        for (size_t i = 0; i < vsize_; i++)
            laikinas[i] = arr_[i];
        delete[] arr_;
        arr_ = laikinas;
    };
```
```c++

        void push_back(T data) {
        if (vsize_ >= cap_){
            resize(vsize_*2);
        }
        arr_[vsize_] = data;
        vsize_++;
    }
```
## Testai

## <int>

### 10000
```shell
10000 std::vector <int> push_back'ų užtruko: 0.0001425 s
10000  Vektoriuksio <int> push_back'ų užtruko: 0.0000498 s

```
### 100000
```shell
100000 std::vector <int> push_back'ų užtruko: 0.0013353 s
100000  Vektoriuksio <int> push_back'ų užtruko: 0.0006459 s
```
### 1000000

```shell
1000000 std::vector <int> push_back'ų užtruko: 0.0132147 s
1000000  Vektoriuksio <int> push_back'ų užtruko: 0.0068194 s
```


### 10000000

```shell
10000000 std::vector <int> push_back'ų užtruko: 0.1538179 s
10000000  Vektoriuksio <int> push_back'ų užtruko: 0.0714277 s

```
### 100000000
```shell
100000000 std::vector <int> push_back'ų užtruko: 1.6257047 s
100000000  Vektoriuksio <int> push_back'ų užtruko: 0.9588834 s

```
## <Studentas>

```shell
10000 std::vector <studentas> push_back'ų užtruko: 0.0024428 s
10000  Vektoriuksio <studentas> push_back'ų užtruko: 0.0025269 s

```
### 100000
```shell
100000 std::vector <studentas> push_back'ų užtruko: 0.0242677 s
100000  Vektoriuksio <studentas> push_back'ų užtruko: 0.0422318 s
```
### 1000000

```shell
1000000 std::vector <studentas> push_back'ų užtruko: 0.2137626 s
1000000  Vektoriuksio <studentas> push_back'ų užtruko: 0.3964607 s

```
### 10000000

```shell
10000000 std::vector <studentas> push_back'ų užtruko: 3.3801065 s
10000000  Vektoriuksio <studentas> push_back'ų užtruko: 3.2683645 s

```
### Perskirstymai

-std::vector - 28
-Vektoriuksio - 23
