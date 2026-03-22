<div align="center">

![BMSTU C++ Labs Banner](figures/banner.svg)

# 📦 BMSTU C++ Labs

_«Понимание структур данных — фундамент, на котором строятся все алгоритмы.»_

**Лабораторные работы по C++ — структуры данных, ассоциативные контейнеры и прикладные задачи**

[![C++17](https://img.shields.io/badge/C++-17-818CF8?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org)
[![STL](https://img.shields.io/badge/STL-Containers-C4B5FD?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.cppreference.com)
[![BMSTU](https://img.shields.io/badge/BMSTU-Kaluga-6366F1?style=for-the-badge&logo=education&logoColor=white)](https://bmstu.ru)
[![License: MIT](https://img.shields.io/badge/License-MIT-C4B5FD?style=for-the-badge)](LICENSE)

[Структуры данных](#-lab-1--структуры-данных) · [Ассоциативные контейнеры](#-lab-2--ассоциативные-контейнеры) · [Управление рейсами](#-lab-3--управление-рейсами) · [Сборка](#-сборка)

---

</div>

## ✦ О проекте

Консолидированный репозиторий лабораторных работ по курсам **«Структуры и организация данных»** и **«Алгоритмы и структуры данных»** в МГТУ им. Н.Э. Баумана (Калужский филиал).

Каждая структура данных реализована в двух вариантах — **статическом** (массив фиксированного размера) и **динамическом** (связный список) — для демонстрации различий в управлении памятью.

---

## ✦ Lab 1 — Структуры данных

### Static (массив)

| Файл | Структура | Особенности |
|---|---|---|
| `static/FIFO.cpp` | Циклическая очередь | Модульная арифметика для wraparound |
| `static/LIFO.cpp` | Стек | Template с параметром размера `N` |
| `static/List.cpp` | Список | Вставка со сдвигом элементов |
| `static/Set.cpp` | Множество | Проверка уникальности при добавлении |

### Dynamic (связный список)

| Файл | Структура | Особенности |
|---|---|---|
| `dynamic/FIFO.cpp` | Очередь | Node-based, front/rear pointers |
| `dynamic/LIFO.cpp` | Стек | Push/pop через указатели |
| `dynamic/List.cpp` | Список | Вставка/удаление по индексу |
| `dynamic/Set.cpp` | Множество | Линейный поиск для uniqueness |

### Tree

| Файл | Структура | Особенности |
|---|---|---|
| `tree/BinaryTree.cpp` | Бинарное дерево поиска | Insert, Search, Delete + 3 обхода (in/pre/post-order) |

### Library (header-версия)

Выделенные `.h`-файлы для повторного использования:

```
library/
├── List.h            # Статический список (template)
├── dynamic_List.h    # Динамический список (template)
├── process.h         # Демо-структура Process {id, status, name}
└── main.cpp          # Пример использования
```

---

## ✦ Lab 2 — Ассоциативные контейнеры

Практические задачи на `std::map`, `std::set`, `std::unordered_map`:

| Файл | Задача | Контейнеры |
|---|---|---|
| `common_letters.cpp` | Общие буквы в строках | `set<char>`, `unordered_set<string>` |
| `common_letters_v2.cpp` | То же, альтернативный подход | `vector<map<char,int>>` |
| `ngrams.cpp` | Частотный анализ N-грамм | `unordered_map<string,int>` |
| `filesystem_paths.cpp` | Извлечение путей из ФС | `set<string>` |
| `duplicate_detector.cpp` | Детектор повторов в последовательности | `map<string,int>` |
| `repeat_numbers.cpp` | Поиск дубликатов чисел | `set<string>` |

---

## ✦ Lab 3 — Управление рейсами

Система управления пассажирами авиарейсов — 3 итерации одной задачи:

| Версия | Файл | Подход |
|---|---|---|
| **v1** | `v1_basic.cpp` | `map<int, string>`, ручной парсинг строк |
| **v2** | `v2_refactored.cpp` | `map<int, set<string>>`, `istringstream` |
| **v3** | `v3_production.cpp` | Модульная архитектура (6 методов), валидация, файловый вывод |

### Эволюция решения

```
v1: Монолитный код          →  v2: Правильные структуры   →  v3: Production-ready
    map<int, string>             map<int, set<string>>         Модульность
    Ручной парсинг               istringstream                 Error handling
    Без валидации                Минимальная валидация          Файловый I/O
```

### Команды

| Команда | Описание |
|---|---|
| `FLY <id> <passengers>` | Создать рейс с пассажирами |
| `GROUND <id>` | Удалить рейс |
| `SEAT <id> <name>` | Добавить пассажира |
| `CANCEL <id> <name>` | Снять пассажира |
| `PRINT <id>` | Вывести список пассажиров |

---

## ✦ Структура проекта

```
BMSTU-CPP-Labs/
├── 01-data-structures/
│   ├── static/                    # Реализации на массивах
│   │   ├── FIFO.cpp               #   Циклическая очередь
│   │   ├── LIFO.cpp               #   Стек
│   │   ├── List.cpp               #   Список
│   │   └── Set.cpp                #   Множество
│   ├── dynamic/                   # Реализации на связных списках
│   │   ├── FIFO.cpp               #   Очередь
│   │   ├── LIFO.cpp               #   Стек
│   │   ├── List.cpp               #   Список
│   │   └── Set.cpp                #   Множество
│   ├── tree/
│   │   └── BinaryTree.cpp         #   BST с тремя обходами
│   └── library/                   # Header-библиотека
│       ├── List.h                 #   Статический список
│       ├── dynamic_List.h         #   Динамический список
│       ├── process.h              #   Демо-структура
│       └── main.cpp               #   Пример использования
│
├── 02-associative-containers/     # Задачи на ассоциативные контейнеры
│   ├── common_letters.cpp         #   Общие буквы (set)
│   ├── common_letters_v2.cpp      #   Общие буквы (map)
│   ├── ngrams.cpp                 #   N-граммы (unordered_map)
│   ├── filesystem_paths.cpp       #   Пути ФС (set)
│   ├── duplicate_detector.cpp     #   Детектор повторов (map)
│   └── repeat_numbers.cpp         #   Дубликаты (set)
│
├── 03-flight-management/          # Управление рейсами
│   ├── v1_basic.cpp               #   Базовая версия
│   ├── v2_refactored.cpp          #   Рефакторинг
│   ├── v3_production.cpp          #   Production-версия
│   └── Input.txt                  #   Тестовые данные
│
├── figures/
│   └── banner.svg
├── .gitignore
└── README.md
```

---

## ✦ Сборка

Каждый `.cpp` файл — самодостаточная программа с `main()`:

```bash
# Любой файл
g++ -std=c++17 -o program 01-data-structures/static/FIFO.cpp && ./program

# Library-версия (с заголовками)
g++ -std=c++17 -o library 01-data-structures/library/main.cpp && ./library

# Flight management
g++ -std=c++17 -o flight 03-flight-management/v3_production.cpp && ./flight < 03-flight-management/Input.txt
```

---

## ✦ Сравнение подходов

| Характеристика | Static (массив) | Dynamic (связный список) |
|---|---|---|
| **Размер** | Фиксированный, compile-time | Растёт динамически |
| **Память** | Выделяется сразу | По требованию (`new`/`delete`) |
| **Доступ** | O(1) по индексу | O(n) — обход |
| **Вставка/Удаление** | O(n) — сдвиг элементов | O(1) — перестановка указателей |
| **Cache locality** | Высокая | Низкая |

---

## ✦ Лицензия

MIT License — свободно используйте, форкайте, дорабатывайте.

---

<div align="center">

**Сухацкий Максим** · МГТУ им. Н.Э. Баумана (Калужский филиал) · 2024

[![GitHub](https://img.shields.io/badge/GitHub-Siesher-818CF8?style=flat-square&logo=github)](https://github.com/Siesher)

<br>

<img width="100%" src="https://capsule-render.vercel.app/api?type=waving&color=0:6366F1,50:818CF8,100:C4B5FD&height=100&section=footer"/>

</div>
