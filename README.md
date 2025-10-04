# SO

## 📌 Descrição do Projeto

Este projeto foi desenvolvido no âmbito da unidade curricular de **Sistemas Operativos (SO)** e tem como principal objetivo a **simulação de dois componentes essenciais de um sistema operativo**:

1. **Escalonador de processos em uniprocessador** – Implementa algoritmos de escalonamento que determinam a ordem de execução dos processos, considerando diferentes políticas de gestão de CPU.
2. **Gestão de memória contígua** – Simula um sistema de alocação e libertação de memória, explorando estratégias clássicas (como *First-Fit*, *Best-Fit* e *Worst-Fit*), de forma a compreender como os sistemas reais lidam com a fragmentação e desempenho.

O projeto foi desenvolvido em **C++**, seguindo boas práticas de programação e com suporte a **Doxygen** para geração automática de documentação.

---

## ⚙️ Pré-requisitos

Em Ubuntu, instale os seguintes pacotes antes de compilar:

```bash
sudo apt install build-essential cmake doxygen git
```

Em outras distribuições Linux, instale os pacotes equivalentes.

---

## 📥 Clonar o Repositório

```bash
git clone git@github.com:ua-so-fso/«your-project».git
```

---

## 📄 Geração de Documentação

O código está documentado em **Doxygen**. Para gerar a documentação HTML:

```bash
cd «your-project»/doc
doxygen
firefox html/index.html &
```

---

## 🛠️ Compilação

Na raiz do projeto, crie a pasta `build` e utilize o **CMake**:

```bash
mkdir build
cd build
cmake ../src
make
```

Ou, alternativamente, use o **Ninja**:

```bash
mkdir build
cd build
cmake -G Ninja ../src
ninja
```

---

## 🔧 Configuração do Git

Defina o seu nome e email para commits:

```bash
git config user.name "O Seu Nome"
git config user.email "o.seu@email.com"
```

Ou de forma global:

```bash
git config --global user.name "O Seu Nome"
git config --global user.email "o.seu@email.com"
```

---

## 🧪 Testes

Após a compilação, o binário será gerado em:

```
«your-project»/bin
```

Pode utilizar o programa de teste padrão (`main.cpp`) ou criar novos ficheiros de teste, lembrando-se de os incluir no `CMakeLists.txt`.

---

## 🚀 Principais Competências Demonstradas

* Programação em **C++**.
* Implementação de **algoritmos de escalonamento** de CPU.
* Implementação de **sistemas de alocação de memória**.
* Utilização de **CMake** para gestão e compilação do projeto.
* Geração de documentação automática com **Doxygen**.
* Gestão de código com **Git/GitHub**.

---

## 📚 Aprendizagem e Objetivo

Este projeto permite compreender em profundidade **como os sistemas operativos gerem processos e memória**, oferecendo uma visão prática das estratégias clássicas ensinadas na teoria. Ele combina conceitos fundamentais de **gestão de recursos, eficiência e desempenho** num ambiente simulado, preparando para desafios em desenvolvimento de sistemas de baixo nível e engenharia de software.

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
