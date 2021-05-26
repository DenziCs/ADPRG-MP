#include "ContactResolverIterator.h"

void ContactResolverIterator::resolveContacts(vector<ContactResolver*> contacts) {
	if (contacts.empty()) return;
	for (int i = 0; i < max_iterations; i++) {
		contacts[i]->resolve();
	}
}