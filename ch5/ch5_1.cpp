//
// Created by Razdan, Akhil on 2021/05/20.
//

struct AccountDatabase {
    virtual int getAmount(long account_id) = 0;
    virtual void setAmount(long account_id, int amount) = 0;
};
