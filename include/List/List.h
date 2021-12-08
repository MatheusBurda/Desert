#pragma once

#include <iostream>

namespace List {

    template <class TL>
    class List {
    private:
        /* template Node to use as node of the list */
        template <class TE>
        class Node {
        private:
            Node<TE>* pNext;
            Node<TE>* pPrevious;
            TE* pInfo;

        public:
            Node() {
                pNext = NULL;
                pPrevious = NULL;
                pInfo = NULL;
            }
            ~Node() {
                pNext = NULL;
                pPrevious = NULL;
                pInfo = NULL;
            }
            /* Set next template Node - internal list use */
            void setNext(Node<TE>* pNext) { this->pNext = pNext; }
            /* Get next node of the list */
            Node<TE>* getNext() { return pNext; }
            /* Set previous node */
            void setPrevious(Node<TE>* pPrevious) { this->pPrevious = pPrevious; }
            /* Get previous node */
            Node<TE>* getPrevious() { return pPrevious; }
            /* Sets the pointer the template Node points to*/
            void setInfo(TE* pInfo) { this->pInfo = pInfo; }
            /* Returns the pointer the template Node points to. */
            TE* getInfo() { return pInfo; }
        };

        Node<TL>* pFirst;
        Node<TL>* pLast;
        unsigned int size;

    public:
        List();
        ~List();

        void clear();
        unsigned int getSize() { return size; }
        TL* operator[](int x);
        void push(TL* pInfo);
        TL* pop(TL* pInfo);
        TL* pop(int index);

    private:
        void setNode(Node<TL>* pNode);
        Node<TL>* getpFirst() { return pFirst; }
        Node<TL>* getpLast() { return pLast; }
    };

    template <class TL>
    List<TL>::List() :
    pFirst(),
    pLast(),
    size(0) {
        clear();
    }

    template <class TL>
    List<TL>::~List() {
        clear();
    }

    /* Delete the whole List */
    template <class TL>
    void List<TL>::clear() {
        Node<TL>* paux1;
        Node<TL>* paux2;

        paux1 = pFirst;
        paux2 = paux1;

        while (paux1 != NULL) {
            delete (paux1->getInfo());
            paux2 = paux1->getNext();
            delete (paux1);
            paux1 = paux2;
            size--;
        }

        pFirst = NULL;
        pLast = NULL;
    }

    /* Add new Node to List - internal use */
    template <class TL>
    void List<TL>::setNode(Node<TL>* pNode) {
        if (pNode != NULL) {
            if (pFirst == NULL) {
                pFirst = pNode;
                pLast = pNode;
            } else {
                pLast->setNext(pNode);
                pNode->setPrevious(pLast);
                pLast = pNode;
            }
            size++;

        } else {
            std::cout << "ERROR: on List<TL>::setNode -> Pointer pNode == NULL. Insert not succeeded." << std::endl;
        }
    }

    /* Iterate through the list, similar to a static vector. Returns the pointer the template list points to.  */
    template <class TL>
    TL* List<TL>::operator[](int index) {
        if (index >= size || index < 0) {
            std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries." << std::endl;
            exit(1);
        }

        Node<TL>* pAux = pFirst;
        for (int i = 0; i < index; i++) {
            pAux = pAux->getNext();
        }

        if (pAux == NULL) {
            std::cout << "ERROR: on template operator[] pAux == NULL." << std::endl;
            exit(1);
        }
        return pAux->getInfo();
    }

    /* push new node to the template list */
    template <class TL>
    void List<TL>::push(TL* pInfo) {
        if (pInfo != NULL) {
            Node<TL>* pNode = NULL;
            pNode = new Node<TL>();
            pNode->setInfo(pInfo);
            setNode(pNode);
        }

        else {
            std::cout << "ERROR: on List<TL>::push -> pInfo == NULL" << std::endl;
        }
    }

    /* Pops a specific element fom list given by the information. Returns the element popped from list.*/
    template <class TL>
    TL* List<TL>::pop(TL* pInfo) {
        Node<TL>* pAux = pFirst;
        Node<TL>* pPrev = NULL;
        while (pAux != NULL) {
            if (pAux->getInfo() == pInfo) {
                if (pAux == pFirst)
                    pFirst = pAux->getNext();
                else if (pAux == pLast)
                    pLast = pAux->getPrevious();
                else
                    pPrev->setNext(pAux->getNext());

                delete (pAux);
                size--;
                return pInfo;
            }

            pPrev = pAux;
            pAux = pAux->getNext();
        }
        return NULL;
    }

    /* Pops a specific element fom list given by its index. Returns the element popped from list.*/
    template <class TL>
    TL* List<TL>::pop(int index) {
        if (index >= size || index < 0) {
            std::cout << "ERROR: Segmentation fault on template list. Exceeded boundaries." << std::endl;
            exit(1);
        }

        Node<TL>* pAux = pFirst;
        Node<TL>* pPrev = NULL;

        for (int i = 0; i < index; i++) {
            pPrev = pAux;
            pAux = pAux->getNext();
        }

        if (pAux == pFirst)
            pFirst = pAux->getNext();
        else if (pAux == pLast)
            pLast = pAux->getPrevious();
        else
            pPrev->setNext(pAux->getNext());

        TL* pInfo = pAux->getInfo();

        delete (pAux);
        size--;

        return pInfo;
    }

} // namespace List