# qt-bison-flex

This is a sample project demonstrating the integration of a Flex/Bison parser into a Qt GUI application. Since code demonstration is the main goal of this project, no binaries are included. The project can be opened and compiled with [Qt Creator][creator].

## Setup

Since [kits][kits], compiler paths etc. are almost certainly different between systems, the project does not include the `.pro.user` file. After opening the project, go to the **Projects** tab in Creator and set up your kit(s). You will need to add two custom process steps to the compilation to make sure the lexer and parser are regenerated should you make any changes to Flex or Bison source files:

 * **Custom process step**
   * Command: `bison`
   * Argument: `parser.y`
   * Working directory: `%{sourceDir}`
 * **Custom process step**
   * Command: `flex`
   * Argument: `scanner.l`
   * Working directory: `%{sourceDir}`

Compiling with GCC 5.4.0 on Xubuntu 16.04 _should_ return with only one warning (a `-Wsign-compare` in `scanner.cpp`, line 1102). Your mileage may vary.

## Input files

Once compiled, the executable needs an input file to parse. The simple -- and rather nonsensical -- "Sample input file" (`.sif`) format consists of:

 * An opening line containing `HELLO`
 * Any number of specification lines of the format `max number align alignment`, where `number` must be an integer and `alignment` is either `left`, `right` or `center`.
 * A closing line containing `GOODBYE`
 
For each specification line, the program creates two widgets in the "Parse results" frame: a spinbox from 0 to the number given after `max`, and a label with the text "Sample text" and the alignment specified (left, right or center).

[creator]: http://doc.qt.io/qtcreator/index.html
[kits]: http://doc.qt.io/qtcreator/creator-targets.html
