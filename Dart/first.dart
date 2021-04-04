class Person {
  String name = 'Swap';
  int age = 30;
  
/*  Person(String inputName, int age) {
    name = inputName;
    this.age = age;
*/

	Person(this.name, this.age = 30);
  }
}

addNumbers(num1, num2) {
  print(num1+num2+56);
  return(num1+num2);
}

void main() {
  for (int i = 0; i < 5; i++) {
    print('hello ${i *1000}');
  }
  print(addNumbers(56,32));
  var result = addNumbers(2.4, 6.9);
  
  var a1 = Person('Swapno', 18);
  print(a1.name);
  a1.age = 20;
  print(a1.age);
}

