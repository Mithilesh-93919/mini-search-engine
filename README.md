# Mini Search Engine (C++)

A modular mini search engine built using C++ and STL that supports multi-keyword search, Boolean queries, relevance ranking, and text preprocessing.

---

## Features

- Multi-document indexing
- Multi-keyword search
- Boolean query support (AND / OR)
- Relevance ranking using frequency scoring
- Stop-word filtering
- Case-insensitive search
- Basic word stemming
- Inverted indexing using STL unordered_map
- Modular architecture with separate utility and engine files

---

## Technologies Used

- C++
- STL (unordered_map, vector, set)
- File Handling
- Object-Oriented Programming
- Data Structures & Algorithms

---

## Project Structure

```bash
Mini-Search-Engine/
│
├── data/
│   ├── ai.txt
│   ├── tech.txt
│   ├── sports.txt
│   └── travel.txt
│
├── src/
│   ├── main.cpp
│   ├── search_engine.cpp
│   ├── search_engine.h
│   ├── utils.cpp
│   └── utils.h
│
├── output/
├── README.md
└── .gitignore
```

---

## How It Works

1. Documents are loaded from text files.
2. Text preprocessing is applied:
   - lowercase conversion
   - punctuation removal
   - stop-word filtering
   - stemming
3. An inverted index is created.
4. User queries are processed and ranked based on keyword relevance.

---

## Supported Queries

### Multi-Keyword Search

```text
technology ai sports
```

### Boolean Queries

```text
ai AND technology
```

```text
sports OR travel
```

---

## Compilation

```bash
g++ src/main.cpp src/search_engine.cpp src/utils.cpp -o searchengine
```

---

## Run

```bash
.\searchengine
```

---

## Sample Output

```text
========================
SEARCH RESULTS
========================

data/sports.txt | Score: 3
data/ai.txt     | Score: 1

Results Found: 2
```

---

## Concepts Demonstrated

- Inverted Indexing
- Hashing
- Searching Algorithms
- Text Processing
- Ranking Systems
- STL Optimization
- Modular Programming

---

## Future Improvements

- Phrase searching
- Search history
- TF-IDF ranking
- File crawling
- GUI/Web Interface

---

## Author

BOORGULA MITHILESH
