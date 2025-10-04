# SO

## 📌 Project Description

This project was developed as part of the Operating Systems (SO/FSO) course unit and aims to simulate two essential components of an operating system:

- **Uniprocessor Process Scheduler** – Implements scheduling algorithms that determine the execution order of processes, considering different CPU management policies.  
- **Contiguous Memory Management** – Simulates a memory allocation and deallocation system, exploring classical strategies (such as First-Fit, Best-Fit, and Worst-Fit) to understand how real systems deal with fragmentation and performance.

The project was developed in **C++**, following best programming practices and with support for **Doxygen** for automatic documentation generation.

---

## ⚙️ Prerequisites

On **Ubuntu**, install the following packages before compiling:

```bash
sudo apt install build-essential cmake doxygen git
```

Em outras distribuições Linux, instale os pacotes equivalentes.

---

## 📥 Clone the Repository

```bash
git clone git@github.com:ua-so-fso/«your-project».git
```

---

## 📄 Documentation Generation

The code is documented with Doxygen. To generate HTML documentation:

```bash
cd «your-project»/doc
doxygen
firefox html/index.html &
```

---

## 🛠️ Compilation

In the project root, create the build folder and use CMake:

```bash
mkdir build
cd build
cmake ../src
make
```

Or alternatively, use Ninja:

```bash
mkdir build
cd build
cmake -G Ninja ../src
ninja
```

---

## 🔧 Git Configuration

Set your name and email for commits:

```bash
git config user.name "Your Name"
git config user.email "your@email.com"
```

Or globally:

```bash
git config --global user.name "Your Name"
git config --global user.email "your@email.com"
```

---

## 🧪 Tests

After compilation, the binary will be generated in:

```
«your-project»/bin
```

You can use the default test program (main.cpp) or create new test files, remembering to include them in the CMakeLists.txt.

---

## 🚀 Main Skills Demonstrated

* Programming in C++
* Implementation of CPU scheduling algorithms
* Implementation of memory allocation systems
* Project build and management with CMake
* Automatic documentation generation with Doxygen
* Version control with Git/GitHub

---

## 📚 Learning Outcomes and Goal

This project provides a deeper understanding of how operating systems manage processes and memory, offering a practical view of classical strategies taught in theory.

It combines fundamental concepts of resource management, efficiency, and performance in a simulated environment, preparing students for challenges in low-level systems development and software engineering.

******
******
## Prerequisites
On Ubuntu you need the following packages installed: 
build-essential, cmake, doxygen, and git.
```
sudo apt install build-essential cmake doxygen git
```
In other Linux distributions you need equivalent packages installed.
******
## Checking access to the GibHub repositories
The best way to access your repositories in GitHub is having a public SSH Key to your computer there.
If you don't have one, proceed as follows:
- In your computer, in Linux, check if you have, in your home directory, a folder named <tt>.ssh</tt> with a file whose name ends in <tt>.pub</tt>.
- If not, run command <code>ssh-keygen</code>. 
  It will create the folder, if necessary, and 2 files.
- The file with termination <tt>.pub</tt> contains your public key.
- In GihHub, press your icon (at top right corner) and choose <tt>Settings</tt>
- In the page that appears, choose <tt>SSH and GPG Keys</tt>. 
- Then press the <tt>New SSH Key</tt> button.
- Fill a title (typically the name of your computer) and copy the contains of the <tt>.pub</tt> to the key field.
- Finally, press the <tt>Add SSH Key</tt> button.
******
## Cloning the repo
In a directory of your choice, clone the project to your computer
```
cd «directory-of-your-choice»
git clone https://git@github.com:ua-so-fso/«your-project»
```
******
## Generating documentation
The code is documented in doxygen. So, you can easily generate html documentation pages.
```
cd «directory-of-your-choice»
cd somm22nm/doc
doxygen
```
Then, you can display the pages running (inside the doc directory)
```
firefox html/index.html &
```
Of course, you can replace firefox with your favorite browser.
******
## Preparing the compilation environment
In a terminal, enter the base directory of your project, create the build directory,
and use cmake to prepare make
```
cd «directory-of-your-choice»
cd «your-project»
mkdir build
cd build
cmake ../src
```
If you prefer ninja, instead of make,
```
cd «directory-of-your-choice»
cd «your-project»
mkdir build
cd build
cmake -G Ninja ../src
```
******
## Building the code
In a terminal, enter the build directory of your project and run make or ninja
```
cd «directory-of-your-choice»
cd «your-project»«your-project»«your-project»/build
make
```
or
```
cd «directory-of-your-choice»
cd «your-project»/build
ninja
```
******
## Setting your user name and email in Git
Commands
```
cd «directory-of-your-choice»
cd «your-project»
git config user.name "«your name»"
git config user.email "«your email»"
```
allows you to set your user name and email for this repository.
If you want to apply the settings to all repositories in the computer, run the followings commands instead.
```
cd «directory-of-your-choice»
cd «your-project»
git config --global user.name "«your name»"
git config --global user.email "«your email»"
```
******
## Testing the code
After building the code, a program will be put in the <tt>«your-project»/bin</tt> directory. 
It is a default test program delivered with the base code.
You may edit it (<tt>main.cpp</tt>) to write your own tests.
Alternatively, you can write new test programs.
In this case, do not forget to add them to the main <tt>CMakeList.txt</tt> file.
