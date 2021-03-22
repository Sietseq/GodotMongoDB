#include "MongoDB.h"

using namespace godot;

void MongoDB::_register_methods()
{
	register_method("Register", &MongoDB::Register);
	register_method("Login", &MongoDB::Login);
}

void MongoDB::_init()
{
}

MongoDB::MongoDB()
{
	mongocxx::instance instance{}; // This should be done only once.
	mongocxx::uri uri("mongodb://localhost:27017");
	_client = new mongocxx::client{ uri };
	db = _client->database("test");
	coll = db["people"];
}

MongoDB::~MongoDB() {}

void MongoDB::Register(String nm, String psw)
{
	auto builder = bsoncxx::builder::stream::document{};
	bsoncxx::document::value doc_value = builder
		<< "name" << nm.alloc_c_string()
		<< "age" << psw.alloc_c_string()
		<< bsoncxx::builder::stream::finalize;
	bsoncxx::document::view doc = doc_value.view();

	bsoncxx::stdx::optional<mongocxx::result::insert_one> result =
		coll.insert_one(doc);
}

int MongoDB::Login(String nm, String psw)
{
	return 0;
}