class Person {
public:
	const char* name;
	const char* surname;
	int id;

public:
	Person(const char* name, const char* surname, int id);
	void print();
};