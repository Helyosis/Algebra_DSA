#include "Person.h"
#include <stdio.h>

const char* person_format = \
"      \\|||/\n"
"      (� �)\n"
",~ooO~~(_)~~~~~~,\n"
"|               |\n"
"|%15s|\n" // Will pad the string to fit in the box
"|               |\n"
"'~~~~~~~~~~~Ooo~'\n"
"     |__|__|\n"
"      || ||\n"
"     ooO Ooo\n"
;

Person::Person(const char* new_name, const char* new_surname, int new_id = -1) {
	name = new_name;
	surname = new_surname;
	id = new_id;
}

void Person::print() {
	char res[15];
	if (id == -1) {
		snprintf(res, 15, "%s %s", name, surname);
	}
	else {
		snprintf(res, 15, "%s %s (%d)", name, surname, id);

	}
	printf(person_format, res);
}