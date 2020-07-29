#include<iostream>
using namespace std;

class ilist_item
{
    public:
        ilist_item(int, ilist_item * = NULL);
        ilist_item *next();
        void next(ilist_item *);
        int value();
        void value(int);

    private:
        int _value;
        ilist_item *_next;
};

class ilist
{
    public:
        ilist();
        int size();
        
        void bump_up_size();
        void bump_down_size();

        void insert(int, ilist_item * = NULL);
        void insert_front(int);
        void insert_end(int);

        ilist_item *find(int);
        void display(ostream & = cout);

        void remove_front();
        void remove_all();
        int remove(int);

    private:
        ilist_item *_head, *_end;
        int _size;

        ilist(const ilist &);
        ilist &operator=(const ilist &);
};

inline ilist_item::ilist_item(int value, ilist_item *item)
{
    _value = value;
    if(!item)
        _next = 0;
    else
    {
        _next = item->_next;
        item->_next = this;
    }
}

inline ilist_item *ilist_item::next()
{
    return _next;
}

inline void ilist_item::next(ilist_item *item)
{
    _next = item;
}

inline int ilist_item::value()
{
    return _value;
}

inline void ilist_item::value(int value)
{
    _value = value;
}


inline ilist::ilist()
{
    _head = _end = 0;
    _size = 0;
}

inline int ilist::size()
{
    return _size;
}

inline void ilist::bump_up_size()
{
    ++_size;
}

inline void ilist::bump_down_size()
{
    --_size;
}

inline void ilist::insert(int value, ilist_item *p)
{
    if(!p)
        insert_front(value);
    else
    {
        new ilist_item(value, p);
        bump_up_size();
    }
}

inline void ilist::insert_front(int value)
{
    ilist_item *p = new ilist_item(value);
    if(!_head)
        _head = _end = p;
    else
    {
        p->next(_head);
        _head = p;
    }
    bump_up_size();
}

inline void ilist::insert_end(int value)
{
    if(!_end)
        _head = _end = new ilist_item(value);
    else
        _end = new ilist_item(value, _end);
    bump_up_size();
}

inline ilist_item *ilist::find(int value)
{
    ilist_item *p = _head;
    while(p)
    {
        if(p->value() == value)
            break;
        p = p->next();
    }
    return p;
}

inline void ilist::display(ostream &os)
{
    os << "\n( " << _size << " ) ( ";
    ilist_item *p = _head;
    while(p)
    {
        os << p->value() << ' ';
        p = p->next();
    }
    os << " )\n";
}

inline void ilist::remove_front()
{
    if(_head)
    {
        ilist_item *p = _head;
        _head = _head->next();
        delete p;
        bump_down_size();
    }
}

inline void ilist::remove_all()
{
    while(_head)
        remove_front();
    _size = 0;
    _head = _end = 0;
}

inline int ilist::remove(int value)
{
    ilist_item *p = _head;
    int elem_cnt = 0;
    while(p && p->value() == value)
    {
        p = p->next();
        remove_front();
        ++elem_cnt;
    }
    if(!p)
        return elem_cnt;

    ilist_item *prev = p;
    p = p->next();
    while(p)
    {
        if(p->value() == value)
        {
            prev->next(p->next());
            delete p;
            ++elem_cnt;
            bump_down_size();
            p = prev->next();
            if(!p)
            {
                _end = prev;
                return elem_cnt;
            }
        }
        else
        {
            prev = p;
            p = p->next();
        }
    }
    return elem_cnt;
}

int main()
{
    ilist mylist;
    int order, choice, value, x;
    cout << "Enter the order(1.insert  2.remove 3.display -1.quit):";
    while(cin >> order && order != -1)
    {
        if(order == 1)
        {
            cout << "Enter the choice(1.insert_front 2.insert_end 3.insert):";
            cin >> choice;
            cout << "Enter the value:";
            cin >> value;
            if(choice == 1)
                mylist.insert_front(value);
            if(choice == 2)
                mylist.insert_end(value);
            if(choice == 3)
            {
                cout << "Enter the element:";
                cin >> x;
                mylist.insert(value, mylist.find(x));
            }
        }
        if(order == 2)
        {
            cout << "Enter the choice(1.remove_one 2.remove_front 3.remove_all):";
            cin >> choice;
            if(choice == 1)
            {
                cout << "Enter the value:";
                cin >> value;
                if(mylist.remove(value))
                    cout << "Remove successfully!" << endl;
                else
                    cout << "Failed!There is no this value." << endl;
            }
            if(choice == 2)
                mylist.remove_front();
            if(choice == 3)
                mylist.remove_all();
        }
        if(order == 3)
            mylist.display();
        cout << "Enter the order(1.insert  2.remove 3.display -1.quit):";
    }
    return 0;
}