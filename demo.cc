#include <iostream>
#include "leveldb/db.h"
 
using namespace std;
 

int main()
{
  leveldb::DB *db;
  leveldb::Options options;
 
  options.create_if_missing = true;
  //options.error_if_exists = true;
 
  // 開啟數據庫
  leveldb::Status s = leveldb::DB::Open(options, "./testdb", &db);

  if (!s.ok())
  {
      cerr << s.ToString() << endl;
      return 1;
  }
 
  // 鍵 = MyKey29，值 = "Hello World!"
  string key = "MyKey29", value = "Hello World!", result;
 
  // 儲存 鍵／值對
  db->Put(leveldb::WriteOptions(), key, value);
 
  // 查詢 MyKey29 鍵的值
  db->Get(leveldb::ReadOptions(), key, &result);
 
  // 輸出值到屏幕
  cout << "result = " << result << endl;

  cout << "print all key" << endl;
  leveldb::Iterator* it = db->NewIterator(leveldb::ReadOptions());
  for (it->SeekToFirst(); it->Valid(); it->Next()) {
      cout << it->key().ToString() << " : "  << it->value().ToString() << endl;
  }
  delete it;

  // 關閉數據庫
  delete db;

  return 0;
}
