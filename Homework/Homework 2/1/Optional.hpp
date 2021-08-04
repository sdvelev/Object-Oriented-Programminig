#pragma once

// Add whatever else is required to exist in or out the class
// as well as whatever you think is good to be declared too

template <typename T>

class Optional {
private:
    T item;
    bool flag;
public: 
    Optional();
    Optional(const T& value);

    friend bool operator==(const Optional<T>& lhs, const Optional<T>& rhs);

    bool is_none() const;
    T get_value() const;

    void setItem(const T& _item);
};

template<typename T>
void Optional<T>::setItem(const T& _item) {
    this->item = _item;
}

template<typename T>
bool operator==(const Optional<T>& lhs, const Optional<T>& rhs) {
    if (lhs.item == rhs.item) {
        return true;
    }
    else {
        return false;
    }
}


template<typename T>
Optional<T>::Optional() {
    this->item = T();
    this->flag = false;
}

template<typename T>
Optional<T>::Optional(const T& value) {
    this->item = value;
    this->flag = true;
}

template<typename T>
bool Optional<T>::is_none() const {
    if (this->flag == false) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
T Optional<T>::get_value() const {
    if (this->is_none()) {
        return T();
    }
    else {
        return this->item;
    }
}