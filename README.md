# Big Integer Arithmetic Algorithms

## Project Outcomes:
Develop a C++ program that uses:
- Stack ADT
- Multiple stacks
- File I/O

## Project overview:
Physical machines have fixed maximum sizes for the representation of numbers.
For instance, integers are often 32 bits and signed, meaning the largest
integer value that can be held is + or - approximately 2 billion. The goal of
this project is to use multiple stack data structures to enable addition and
subtraction of arbitrarily large integers.

![Integer overflow when counting sheep](https://imgs.xkcd.com/comics/cant_sleep.png)

## Project Requirements:
Your application must function as described below:
1. Your program shall adhere to the test suites provided [here](test/). Read
    the tests and create the required files, classes, and methods. This means
    that all tests must pass in their current configuration.
1. The Makefile was provided and can be directly used.
1. Implement a int Stack ADT to support the algorithm.
1. Perform large integer operation using stacks:
    1. prepare the operands and operators so the sign of the second operand
       will be combined with the operator
    1. if a large number is subtracted from a smaller number, reverse the order
       of the subtraction and mark the result as negative
    1. create three stacks, two for operands and one for the result
    1. for both operands, push every digit into the the corresponding stack
       starting from left to right
    1. pop one digit from each operand every time to calculate the result for
       this digit in the result stack
    1. when one operand run out of digit before another, you should provide a 0
       instead
    1. for each decimal place, apply the operation to both digits, include the
       carry and borrow bit from the last round as need, set the new carry and
       borrow for next round
    1. clean up the leading zero in subtraction
1. Display in the desired format

## Code organization:
+ The Stack class and Node class

    Implement an int Stack. Include the node class used in the stack in the
    same set of files (stack.hpp, stack.cpp).

+ The Operand class

    - Models an int operand
    - Keeps the int value as a string
    - Keeps a sign

+ The ArithmeticExpression class

    - Models an binary expression with two operands and one operator
    - Keeps two operands as Operand objects
    - Keeps an operator as a char
    - The operator will be adjusted when the second operand is negative; so
      ``3 + (-2)`` should be adjusted to ``3 - 2`` and ``3 - (-2)`` should be
      adjusted to ``3 + 2``
    - This class supports negative operands!

+ The BigIntegerArithmetic class

    - The class owns a reference to a ArithmeticExpression object and performs
      big integer arithmetic on the expression.
    - To keep it simple, operands used in tests are **all positive** so do not
      worry negative operands!
    - When handling subtraction, the order of the subtrahend and minuend needs
      to be reversed when the subtrahend is greater; the sign of the result
      will be negative and needs to be kept separately in the object; when
      displaying the result, the operands should be displayed in the original
      order. Example: `30 - 45` should be internally calculated as `-(45 -
      30)`.
    - You better store the sign of result separately.
    - The `operandComp` method compares two positive operands; it should
      return a positive value if the first is greater, return zero if two are
      the same, return a negative value if the first is less.

        - you can compare the string length first and then use the
          string::compare method to compare two strings with the same lengths
        - **string::compare() only work well with strings with a same length!**

    - the `getResults` method returns a string containing the output integer.

+ The ExpressionReader class

    - The constructor will open a text file as input for future operations.
    - the `processNextExpression` method to read the next expression (one line)
      from the input data file as shown below and produce the output.

+ The main.cpp driver file is provided

## Sample data file:
The operands will be **all positive** in the tests for simplicity.

```
12 + 5
5 + 12
12 - 5
5 - 12
364287462834623846283426384 + 923742938742934723947239847
364287462834623846283426384 - 923742938742934723947239847
```

## Sample run:
The output may contain long lines that will wrap in the display. Each
expression should be a long line when you generate them!

```
12 + 5 = 17
----------
5 + 12 = 17
----------
12 - 5 = 7
----------
5 - 12 = -7
----------
364287463834623846283426384 + 923742938742934723947239847 = 1288030402577558570230666231
----------
364287463834623846283426384 - 923742938742934723947239847 = -559455474908310877663813463
----------
```

## Implementation Notes:
1. Create a project that is object oriented, therefore there should be several
   classes.
1. The input file will match the exact format given above.
1. Your program must compile and pass a tests listed above.
    - This application must be compiled by running `make main` and shall create
        an executable file called `main`.
    - All tests must pass by running together with `make test-all`. You can run
        individual test during development.
1. You classes must be memory leak free. Memory leakage will be checked and
   graded in autograding. You either avoid dynamic data or provide big three.

## Submission Requirements:
1. All code must be added and committed to your local git repository.
2. All code must be pushed to the GitHub repository created when you "accepted"
   the assignment.
    1. After pushing, with `git push origin main`, visit the web URL of your
       repository to verify that your code is there. If you don't see the code
       there, then we can't see it either.
3. Your code must compile and run. The auto-grading tests will indicate your
   score for your submission.
    1. The auto-grading build should begin automatically when you push your
       code to GitHub.
    2. If your program will not compile, the graders will not be responsible
       for trying to test it.
    3. You should get an email regarding the status of your build, if it does
       not pass, keep trying.

## Building and Testing

A `Makefile` is provided to automate compilation and testing:
- **Compile main calculator program**: `make main`
- **Run main calculator**: `make test-run` or `./main`
- **Run all unit tests**: `make test-all`
- **Run individual unit tests**:
  - `make test-1-node`: Node unit tests.
  - `make test-2-stack`: Stack unit tests.
  - `make test-3-operand`: Operand unit tests.
  - `make test-4-arithmetic-expression`: Arithmetic expression unit tests.
  - `make test-5a-big-integer-arithmetic`: Big integer arithmetic unit tests part 1.
  - `make test-5b-big-integer-arithmetic`: Big integer arithmetic unit tests part 2.
  - `make test-6-expression-reader`: Expression reader unit tests.
- **Run memory leak check**: `make test-mem` (runs Valgrind on stack tests).
- **Clean build artifacts**: `make clean`

> **Note for macOS / Xcode users**: Valgrind is not natively supported on macOS. If you are using macOS command line tools (Xcode), you cannot directly execute `valgrind` / `make test-mem` locally. Please launch a **GitHub Codespaces** instance on GitHub (or use a Linux container) to run memory leak checks.

## Important Notes:
- Projects will be graded on whether they correctly solve the problem, and
  whether they adhere to good programming practices.
- Projects must be received by the time specified on the due date.
- Please review the academic honesty policy.
    - Note that viewing another student's solution, whether in whole or in
      part, is considered academic dishonesty.
    - Also note that submitting code obtained through the Internet or other
      sources, whether in whole or in part, is considered academic dishonesty.
    - All programs submitted will be reviewed for evidence of academic
      dishonesty, and all violations will be handled accordingly.

## Grading Information:
- Breakdown
    + 80% GitHub Auto-grading
    + 10% Coding style (naming convention, neatness of code, etc)
    + 10% Code organization (modular design, separate files, headers, etc.)

## Checking Auto-grading Results:

After you push your code, GitHub will automatically run tests on your
submission. To view the results:

1. On your GitHub repository page, click the :arrow_forward: **Actions** tab at
   the top
2. Click on the most recent workflow run (it will show your commit message)
3. Wait until the run finishes (showing either ✅ or ❌)
4. Scroll down to "Autograding summary" section to see the summary
5. It will display:
   - **Points:** Your score (e.g., 10/10)
   - ✅ All tests passed! or ❌ Some tests failed
6. If tests failed, click the "Autograding" button above to see detailed logs:
   - Expand the **education/autograding@v1** step to see which tests failed
   - Look for :x: marks to identify specific failures
