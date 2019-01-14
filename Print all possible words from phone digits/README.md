# Print all possible words from phone digits

* Before the advent of QWERTY keyboards, texts and numbers were placed on the same key. For example, 2 has “ABC” if we wanted to write anything starting with ‘A’ we need to type key 2 once. If we wanted to type ‘B’, press key 2 twice and thrice for typing ‘C’. below is a picture of such keypad.
Given a keypad as shown in the diagram, and a n digit number, list all words which are possible by pressing these numbers.

For example if input number is 234, possible words which can be formed are (Alphabetical order):
adg adh adi aeg aeh aei afg afh afi bdg bdh bdi beg beh bei bfg bfh bfi cdg cdh cdi ceg ceh cei cfg cfh cfi

```
Input  : number[] = { 5, 4} 
Output : jg jh ji kg kh ki lg lh li

Input  : number[] = { 0, 9, 5} 
Output : wj wk wl xj xk xl yj yk yl zj zk zl
```

