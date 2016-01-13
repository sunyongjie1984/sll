#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

// #include <exception>
#include "slln.h"
#include "my_exception.h"

// template function operator<< declaration
template <class Type> ostream& operator<<(ostream&, const sll<Type> &);

// template function globalPrint declaration
template <class Type> ostream& globalPrint(ostream&, const sll<Type> &);

// template function operator>> declaration
template <class Type> istream& operator>>(istream&, sll<Type>&);

// template class sll definition
template <class Type> class sll {
	// friend function declaration
	// this function(operator<< <Type>) is an instance of template function operator<<
	friend ostream& operator<< <Type>(ostream&, sll<Type> const &);

	// friend function declaration
	// this function(globalPrint<Type>) is an instance of template function globalPrint
	friend ostream& globalPrint<Type>(ostream&, sll<Type> const &);

	// friend function declaration
	// this function(operator>> <Type>) is an instance of template function operator>>
	friend istream& operator>> <Type>(istream&, sll<Type>&);
public:
	sll(): head(NULL), tail(NULL) { }
	sll(const int& n);
	// use the overloaded operator >>
	sll(istream& is) { is >> *this; }
	sll(sll const & object)
	{
		slln<Type>* n = new slln<Type>;
		slln<Type>* q = object.head;
		n->info = q->info;
		setHead(n);
		q = q->next;
		while (NULL != q)
		{
			slln<Type>* h = new slln<Type>;
			h->info = q->info;
			n->next = h;
			n = h;
			q = q->next;
		}
		tail = n;
	}
	~sll();

	void setHead(slln<Type>* p) { head = p; }
	void setTail(slln<Type>* p) { tail = p; }

	bool isEmpty() const { return head == NULL; }
	bool isInList(Type) const;

	slln<Type>* getHead() const { return head; }
	slln<Type>* getTail() const { return tail; }

	void addToHead(Type);
	void addToTail(Type);

	bool deleteFromHead();
	bool deleteFromTail();
	bool deleteNode(Type);

	// if a member function is logically does not modify the data member
	// it is strongly recommended that we define that function as
	// a const member function
	// because a non const member function can not be involed by the
	// const object
private:
	void destroy();

	slln<Type>* head;
	slln<Type>* tail;
};

// because sll<Type> is a class name, like any other non-template classes
template <class Type> sll<Type>::sll(int const & n)
{
	head = new slln<Type>;
	slln<Type>* p1 = head;
	cout << "please input the first element :" << endl;
	cin >> head->info;
	for (int i = 0; i < n - 1; i++)
	{
		slln<Type>* p2 = new slln<Type>;
		cout << "the "<< i + 2 << " element: " << endl;
		cin >> p2->info;
		p1->next = p2;
		p1 = p2;
	}
	tail = p1;
	tail->next = NULL;
}

template <class Type> sll<Type>::~sll()
{
	destroy();
}

template <class Type> void sll<Type>::destroy()
{
	for (slln<Type>* p; !isEmpty(); )
	{
		p = head->next;
		delete head;
		head = p;
	}
}

template <class Type> void sll<Type>::addToHead(Type el)
{
	head = new slln<Type>(el, head);
	if (tail == NULL)
	{
		tail = head;
	}
}

template <class Type> void sll<Type>::addToTail(Type el)
{
	if (tail != NULL)
	{
		// tail->next = new slln<Type>(el);
		// tail = tail->next;
        tail = tail->next = new slln<Type>(el);
	}
	else
	{
		head = tail = new slln<Type>(el);
	}
}

template <class Type> bool sll<Type>::deleteFromHead()
{
	bool bFlag; // use one flay to get rid of the multi-return statement
	if (isEmpty())
	{
		bFlag = false;
	}
	else
	{
		Type el = head->info;
		slln<Type>* tmp = head;
		if (head == tail) // only one node
		{
			head = tail = NULL;
		}
		else
		{
			head = head->next;
		}
		delete tmp; // if tmp = 0, no dangerous to delete a NULL pointer
		// if tmp != 0, it is a normal ok
		bFlag = true;
	}
	return bFlag;
}

template <class Type> bool sll<Type>::deleteFromTail()
{
	bool bFlag;
	if (isEmpty())
	{
		bFlag = false;
	}
	else
	{
		if (head == tail) // only one node
		{
			delete head;
			head = tail = NULL;
		}
		else
		{
			slln<Type>* tmp;
			for (tmp = head; tmp->next != tail; tmp = tmp->next);
			delete tail;
			tail = tmp;
			tail->next = NULL;
		}
		bFlag = true;
	}
	return bFlag;
}

template <class Type> bool sll<Type>::deleteNode(Type el)
{
	bool bFlag = false;
	if (!isEmpty())
	{
		if (head == tail && el == head->info)
		{
			delete head;
			head = tail = NULL;
		}
		else if (el == head->info)
		{
			slln<Type>* tmp = head;
			head = head->next;
			delete tmp;
		}
		else
		{
			slln<Type>* pred;
			slln<Type>* tmp;
			for (pred = head, tmp = head->next; tmp != NULL && !(tmp->info == el);pred = pred->next, tmp = tmp->next);
			if (tmp != NULL)
			{
				pred->next = tmp->next;
				if (tmp == tail)
				{
					tail = pred;
				}
				delete tmp;
			}
		}
		bFlag = true;
	}
	return bFlag;
}

template <class Type> bool sll<Type>::isInList(Type el) const
{
	slln<Type>* tmp;
	for (tmp = head; tmp != NULL && !(tmp->info == el); tmp = tmp->next);
	return tmp != NULL;
}

// global template function
template <class Type> ostream& operator<<(ostream& os, sll<Type> const & object)
{
	for (slln<Type>* p = object.getHead(); p != NULL; p = p->next)
	{
		os << p->info << " ";
	}
	return os;
}

// global template function
template <class Type> ostream& globalPrint(ostream& os, sll<Type> const & object)
{
	for (const slln<Type>* p = object.getHead(); p != NULL; p = p->next)
	{
		os << p->info << " ";
	}
	return os;
}

// global template function
template <class Type> istream& operator>>(istream& is, sll<Type>& object)
{
	slln<Type>* h = new slln<Type>;
	object.setHead(h);
	cin >> h->info;
	Type x;
	try
	{
		// make sure loop input and always true only if the ctrl + d, end of file
		while (cin >> x || !cin.eof())
		{
			// expecting an int, but a char, cin.fail() become true
			if (cin.fail())
			{
                // std::exception a("cin.fail() exception");
                my_exception a("cin.fail() exception");
				throw a;
			}
			slln<Type>* p2 = new slln<Type>;
			p2->info = x;
			h->next = p2;
			h = p2;
		}
	}
    catch (my_exception const & e)
	{
		cout << e.what() << endl;
		cin.clear();
		cin.ignore();
		object.destroy();
		cout << "re input data" << endl;
		cin >> object;
	}
	object.setTail(h);
	return is;
}

#endif
