
#ifndef JUSTFORFUN_H_
#define JUSTFORFUN_H_

template <typename listdata>
class LIST
{
privare:
    
}






    struct Node
    {
        Node* linknext;
        Node* linkprevious;
        listdata data;
        Node (listdata newdata)
        {
            data = newdata;
            linknext = linkprevious = NULL;
        }
    }
    int size;
    Node* Iterator;
    Node* start;
    Node* stop;
#endif
