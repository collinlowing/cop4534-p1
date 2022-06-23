//
// Created by cel on 6/13/22.
//

#ifndef P1_HASHITEM_H
#define P1_HASHITEM_H


class HashItem {
private:
    std::string userID;
    std::string password;
public:
    HashItem();

    HashItem(std::string userID, std::string password);

    std::string getUserID();

    void setUserID(std::string userID);

    std::string getPassword();

    void setPassword(std::string password);
};


#endif //P1_HASHITEM_H
