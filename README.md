# TStat
Tool for Statistical Operations in Physics

## Examples

```c++
TStat::Double msr1, msr2;

msr1 = 5.43; // no errors
msr1 = msr1  +0.45_err  -0.67_err; // add asymmetric errors

msr2 = 12.34 +1.43_err  -2.45_err; // assign directly

// it could be cout'd, as well
cout << msr << endl;

// Add asymmetric errors // TODO
TStat::Double msr = msr1 + msr2;
