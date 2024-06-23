//
// Created by trung on 31/05/2024.
//

#ifndef CONTEXTDATA_H
#define CONTEXTDATA_H



class ContextData {
private:
    int errorCounter = 0;
public:
    void incErrorCounter();
    void clearErrorCounter();
    void show() const;
};

#endif //CONTEXTDATA_H
