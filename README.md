# 🔄 Set Relations Operations

![C++](https://img.shields.io/badge/C++-17-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)
![Build](https://img.shields.io/badge/build-passing-brightgreen.svg)
![Windows](https://img.shields.io/badge/platform-Windows-lightgrey.svg)

A comprehensive C++ program for performing advanced set operations and relation manipulations between two correspondences (A and B). This tool supports union, intersection, difference, symmetric difference, inversion, and composition operations on mathematical relations.

## ✨ Features

- 🔄 **Multiple Set Operations**: Union, intersection, difference, and symmetric difference
- 🔁 **Relation Inversion**: Reverse domain and codomain of relations
- 🧩 **Relation Composition**: Compose two relations (A∘B and B∘A)
- 🌐 **Unicode Support**: Full UTF-8 compatibility for mathematical symbols
- ✅ **Input Validation**: Ensures proper set and relation input
- 📊 **Visual Output**: Clear formatting of all operation results

## 🛠️ Installation & Usage

### Prerequisites
- Windows OS (for Unicode support)
- C++ compiler with C++17 support
- Standard Template Library (STL)

### Compilation
```bash
g++ -std=c++17 set_relations.cpp -o set_relations
```

### Execution
```bash
set_relations.exe
```

## 📖 How It Works

The program processes two correspondences A and B, each consisting of:
- Domain set (X for A, U for B)
- Codomain set (Y for A, V for B)  
- Relation graph (G for A, F for B)

### Operations Performed:
1. **Union**: A ∪ B
2. **Intersection**: A ∩ B  
3. **Difference**: B \ A and A \ B
4. **Symmetric Difference**: A Δ B
5. **Inversion**: A⁻¹ and B⁻¹
6. **Composition**: A∘B and B∘A

## 🧮 Example Input

```
Введите мощность X: 2
Введите мощность Y: 2  
Введите мощность G: 2
Вводите значения X:
Введите 1-e значение: 1
Введите 2-e значение: 2
Вводите значения Y:
Введите 1-e значение: 3
Введите 2-e значение: 4
вводите значения G:
Введите 1-ю пару: 1 3
Введите 2-ю пару: 2 4

Введите мощность U: 2
Введите мощность V: 2
Введите мощность F: 2
Вводите значения U:
Введите 1-e значение: 2
Введите 2-e значение: 5
Вводите значения V:
Введите 1-e значение: 4
Введите 2-e значение: 6
вводите значения F:
Введите 1-ю пару: 2 4
Введите 2-ю пару: 5 6
```

## 📊 Sample Output

```
-------ОБЪЕДИНЕНИЕ A и В-------
       ОБЪЕДИНЕНИЕ X и U
1 2 5 
       ОБЪЕДИНЕНИЕ Y и V
3 4 6 
       ОБЪЕДИНЕНИЕ G и F
<1,3> <2,4> <5,6> 
```

## 🏗️ Code Structure

- **Memory Management**: Dynamic allocation for sets and relations
- **Vector Operations**: STL vectors for flexible storage of results
- **Nested Loops**: For comprehensive comparison of set elements
- **Flag System**: Efficient duplicate detection and validation

## 🎯 Key Functions

1. **Union Operations**: Combine elements from both sets/relations
2. **Intersection Operations**: Find common elements between sets/relations  
3. **Difference Operations**: Extract unique elements from sets/relations
4. **Inversion Operations**: Reverse domain and codomain of relations
5. **Composition Operations**: Create new relations from existing ones

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the LICENSE file for details.

## 🙋‍♂️ Author

**Vladus2007**
- GitHub: [@Vladus2007](https://github.com/Vladus2007)

## 🎓 Academic Use

This program is particularly useful for:
- Discrete mathematics courses
- Set theory applications
- Relation algebra studies
- Computer science theory classes

## 🔮 Future Enhancements

- [ ] Graphical visualization of relations
- [ ] Support for n-ary relations
- [ ] Additional relational operations (closure, equivalence classes)
- [ ] File I/O for saving and loading relations
- [ ] Cross-platform compatibility

---

⭐️ If you find this project useful, please give it a star!
