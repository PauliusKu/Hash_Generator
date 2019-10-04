# Hash_Generator
## Hash Function
This 32-bit hash function creates hex unsigned integer value from two any size strings.
```cpp
std::string hashFunc(std::string& pBlock1, const std::string& pBlock2){
    unsigned int hash = 0xAAAAAAAA;
    unsigned long i = 0;

    pBlock1 += pBlock2;

    for (i = 0; i < pBlock1.size(); ++pBlock1[i], ++i){
        if ((i & 1u) == 0)
            hash ^= hash << 7u ^ (pBlock1[i]) * (hash >> 3u);
        else hash ^= ~((hash << 11u) + ((pBlock1[i] + 0u) ^ (hash >> 5u)));
    }

    return hexToString(hash);
}
```

## Hash Method
This function creates and hashes equal size blocks. Seed is set to ```FCB469D2```.
```cpp
std::string hashAlgo(const std::string& pInp1){
    std::vector<std::string> blocks = makeBlocks(pInp1);
    std::string seed = "FCB469D2";

    for(auto& value: blocks){
        seed = hashFunc(value, seed);
    }
    return seed;
}
```
## Test Results

 |Num|Test|Result|
 |--|-----|-------|
 |1|One symbol collision|OK|
 |2|10000 collision|OK|
 |3|10000 one diff collision|OK|
 |4|Time to hash konstitucija.txt|~0.13s|
 |5|100000 random pairs collision|OK|
 |6|100000 random one diff pairs collision|OK|
 |7|Minimum percentage of bitwise difference|37%|
 |8|Maximum percentage of bitwise difference|100%|
 |9|Average percentage of bitwise difference|92%|
 
## Instal instructions
