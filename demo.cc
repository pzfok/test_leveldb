#include "leveldb/db.h"
#include <iostream>
 
using namespace std;
 
int main()
{
  leveldb::DB *db;
  leveldb::Options options;
 
  options.create_if_missing = true;
 
  // 開啟數據庫
  leveldb::DB::Open(options, "./testdb", &db);
 
  // 鍵 = MyKey29，值 = "Hello World!"
  string key = "MyKey29", value = "Hello World!", result;
 
  // 儲存 鍵／值對
  db->Put(leveldb::WriteOptions(), key, value);
 
  // 查詢 MyKey29 鍵的值
  db->Get(leveldb::ReadOptions(), key, &result);
 
  // 輸出值到屏幕
  cout << "result = " << result << endl;
 
  // 關閉數據庫
  delete db;
 
  return 0;
}
