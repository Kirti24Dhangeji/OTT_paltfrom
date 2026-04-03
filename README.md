# 🎬 OTT Platform Management System (C Project)

## 📌 Overview

This project is a **console-based OTT platform system** developed in C.
It allows an admin to manage and organize movies/series using:

* 🌳 **Binary Search Tree (BST)** for categories
* 🌲 **Sub-tree (BST)** for sub-categories
* 🔗 **Linked List** for storing movie/series details

---

## ⚙️ Features

* 🔐 **Admin Authentication (Password Protected)**
* 📂 Add Main Categories (Movies, Series, etc.)
* 🎭 Add Sub-Categories (Horror, Thriller, etc.)
* 🎥 Add Movies/Series with Ratings
* 🔍 Search Movies/Series
* 📄 Store Data in Files
* ▶️ Display and Play Selected Content (Simulation)

---

## 🧠 Data Structures Used

| Structure          | Purpose                |
| ------------------ | ---------------------- |
| Binary Search Tree | Stores main categories |
| Sub BST            | Stores sub-categories  |
| Linked List        | Stores movies/series   |

---

## 📁 Project Structure

```
project/
│── main.c          # Main program
│── functions.c     # All function implementations
│── functions.h     # Header file (structures + declarations)
│── password.txt    # Stores admin password
│── DisplayList.txt # Stores movie data
│── MainCategory(Movies..).txt # Stores categories
```

---

## 🚀 How to Run

### 1️⃣ Compile the program

```
gcc main.c functions.c -o ott
```

### 2️⃣ Run the program

```
./ott
```

---

## 🔑 Default Requirements

* Create a file named **password.txt**
* Add your admin password inside it

Example:

```
admin123
```

---

## 🖥️ Sample Workflow

1. Enter admin password
2. Add OTT platform name
3. Create categories (Movies, Series)
4. Add sub-categories (Horror, Comedy)
5. Add movies (Conjuring, IT, etc.)
6. Search and play content

---

## ⚠️ Limitations

* ASCII-based BST may cause collisions
* No delete functionality
* File handling is basic
* Console-based UI only

---

## 🔮 Future Improvements

* Add delete/update features
* Improve search efficiency
* Use better hashing instead of ASCII sum
* Add GUI (using C++/Python)
* Store data in database

---

## 👨‍💻 Author

* Your Name

---

## 📜 License

This project is for educational purposes only.
