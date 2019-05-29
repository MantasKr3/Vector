# Vector - Mantas Kraujelis

## Programos paleidimas

### Testas
- `git clone https://github.com/MantasKr3/Vector`
- `cd Vector` 
- `g++  main.cpp -o main` 
- `./main`

### Vector bandymas su 3užd
- `git clonehttps://github.com/MantasKr3/Vector`
- `cd Vector`
- `cd Vektoriukstis`
- `make`
- `./main`


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
```c++
 void erase(size_t val) {
        if (val < 0 || val >= vsize_)
            return;
        vsize_--;
        std::move(&arr_[val + 1], &arr_[vsize_], &arr_[val]);
    }
```
```c++
 void clear()
    {
        vsize_ = 0;
        delete[] arr_;
        arr_ = new T[cap_];
    }
 ```   
```c++
size_t size() const { return vsize_; }
```
```c++
size_t capacity() const { return cap_; }
```
```c++
bool empty()
    {
        if (vsize_ == 0)
            return true;
        else
            return false;
    }
```

## Testai

## int

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
## Studentas

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

- std::vector - 28
- Vektoriuksio - 23

## Išvada - su `<int>` tipo elementais `Vector` veikia sparčiau, nei `std::vector`. O su `<Studentas>` tipo kintamaisiai,su mažu kiekiu studento tipo objektų, `std::vector` veikia greičiau nei `Vector`, su dideliu kiekiu grečiau veikia `Vector` .

# Bandymas su 3 užd


## `Vector` (vektoriukštis)

```shell
100000 studentu GENERAVIMAS uztruko: 0.2256529 s
100000 studentu NUSKAITYMAS uztruko: 0.1906117 s
100000 studentu RUSIAVIMAS IR SPAUSDINIMAS uztruko: 0.4791077 s

```
## `std::vector`

```shell
100000 studentu GENERAVIMAS uztruko: 0.1820543 s
100000 studentu NUSKAITYMAS uztruko: 0.2284102 s
100000 studentu RUSIAVIMAS IR SPAUSDINIMAS uztruko: 0.2386965 s
```
## Išvada su `Vector` (vektoriukšiu) programa veikia ~40% lėčiau,nei su `std::vector`.
