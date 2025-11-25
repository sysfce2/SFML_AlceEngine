# 🛠️ Collections

The ```Collections``` module provides generic container classes designed to manage dynamic collections of data efficiently. It offers custom implementations of lists, pairs, and maps that provide intuitive methods for insertion, removal, iteration, and element access. These structures aim to simplify working with collections while ensuring type safety and clean syntax.

## Behaviour

The module introduces three main template-based classes: ```List<T>```, ```Pair<K, V>```, and ```Map<K, V>```.
Each class encapsulates logic commonly found in standard containers, but with custom handling for exceptions, iterator support, functional operations, and simplified access.

The ```List<T>``` class wraps around a dynamic container for storing ordered elements. It supports iteration, filtering, sorting, insertion, removal, and functional operations such as ```ForEach``` and ```Any```.

The ```Pair<K, V>``` class holds a lightweight key–value pair, typically used internally in the ```Map<K, V>``` class.

The ```Map<K, V>``` class maintains a list of ```Pair<K, V>``` objects, providing key-based access, addition, deletion, search, and iteration.

---

# 🧾 List<T>

A dynamic array structure that stores a sequence of elements of type ```T```, offering access, manipulation, and iteration utilities.

# Constructors
```cpp
List()
List(std::initializer_list<T> values)
```

Creates an empty list or initializes it with given elements.

# Methods

## Add
```cpp
void Add(const T& value)
```

Appends an element to the end of the list.

## Remove
```cpp
void Remove(const T& value)
```

Removes the first occurrence of the specified value.
Throws if the value is not found.

## Get
```cpp
T& Get(size_t index)
const T& Get(size_t index) const
```


Returns the element at the specified index.
Throws if the index is out of bounds.

## Size
```cpp
size_t Size() const
```

Returns the number of elements.

## Clear
```cpp
void Clear()
```

Removes all elements from the list.

## Contains
```cpp
bool Contains(const T& value) const
```

Checks whether an element exists in the list.

## ForEach
```cpp
void ForEach(std::function<void(T&)> action)
```

Applies a function to every element.

## Any
```cpp
bool Any(std::function<bool(const T&)> predicate) const
```

Returns true if any element satisfies a condition.

## Sort
```cpp
void Sort(std::function<bool(const T&, const T&)> comparator)
```

Sorts list elements using a custom comparator.

## Iterators:
```cpp
iterator begin()
iterator end()
const_iterator cbegin() const
const_iterator cend() const
```

Provides support for range-based loops and STL compatibility.

---

# 🧾 Pair<K, V>

A lightweight structure to hold a key–value pair.

# Constructors
```cpp
Pair(const K& key, const V& value)
```

Creates a pair with the given key and value.

## GetKey / GetValue
```cpp
K& GetKey()
V& GetValue()
const K& GetKey() const
const V& GetValue() const
```

Returns references to key and value.

---

# 🧾 Map<K, V>

A key–value collection built on top of ```List<Pair<K, V>>```.

# Methods

## Add
```cpp
void Add(const K& key, const V& value)
```

Adds a new pair.
Throws if the key already exists.

## Get
```cpp
V& Get(const K& key)
const V& Get(const K& key) const
```

Retrieves the value for a given key.
Throws if the key is not found.

## Remove
```cpp
void Remove(const K& key)
```

Deletes a key–value pair.
Throws if the key does not exist.

## Contains
```cpp
bool Contains(const K& key) const
```

Checks if a key is present.

## Count
```cpp
size_t Count() const
```

Returns the number of stored pairs.

## Clear
```cpp
void Clear()
```

Removes all entries.

## Iterators
```cpp
iterator begin()
iterator end()
const_iterator cbegin() const
const_iterator cend() const
```

Enables traversal using range-based for loops.