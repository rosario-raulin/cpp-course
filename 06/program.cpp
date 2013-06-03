#include <iostream>

#include "arraylist.hpp"
#include "list.hpp"
#include "duck.hpp"

void outputDucks(const Collections::ICollection& duckcollection)
{
	std::cout << "The list contains " << duckcollection.getNumElements() << " ducks.\n";
    //int i = 0;
	auto it = duckcollection.getIterator();
	while(it->current())
	{
		reinterpret_cast<Duck*>(it->current())->quack();
		it->next();
        //std::cout << "iteration: " << i++ << std::endl;
	}
	delete it;
}

void dump(const Collections::ICollection* collection) {
    auto it = collection->getIterator();
    while (it->current() != nullptr) {
        ((Duck*)it->current())->quack();
        it->next();
    }
}

int main()
{
	Duck linkedListDuck("quack->quack");
	Duck arrayDuck("quackquack");

	// add ducks
	Collections::SingleLinkedList singleLinkedList;
	for( int i=0; i<5; ++i )
		singleLinkedList.insert( linkedListDuck );
	Collections::ArrayList arrayList;
	for( int i=0; i<5; ++i )
		arrayList.insert( arrayDuck );

	// do some explicit ducking
	reinterpret_cast<Duck*>(arrayList.get(1))->quack();
	reinterpret_cast<Duck*>(arrayList.get(3))->quack();

	// reset an element
	arrayList.set(Duck("kuckuk!"), 3);

	// output per iterator
	outputDucks(arrayList);

	// swap!
	std::cout << "\nSwapping\n";
	Collections::ArrayList arrayListFromLinkedList(singleLinkedList);
    
	Collections::SingleLinkedList singleLinkedListFromArrayList(arrayList);

	// output per loop
	for(unsigned int i=0; i<arrayListFromLinkedList.getNumElements(); ++i)
		reinterpret_cast<Duck*>(arrayListFromLinkedList.get(i))->quack();
    
//    Collections::ArrayList list;
//    Collections::SingleLinkedList slist;
//    
//    Duck ele("duck, duck, duck");
//    Duck ele2("duck->duck");
//    for (int i = 0; i < 5; ++i) {
//        list.insert(ele);
//    }
//    for (int i = 0; i < 5; ++i) {
//        slist.insert(ele2);
//    }
// 
//    Collections::ArrayList slistCopy(slist);
//    Collections::SingleLinkedList arrayCopy(list);
//    
//    dump(&slistCopy);
//    std::cout << slistCopy.getNumElements() << std::endl;
//    
//    dump(&arrayCopy);
//    std::cout << arrayCopy.getNumElements() << std::endl;

	return 0;
}