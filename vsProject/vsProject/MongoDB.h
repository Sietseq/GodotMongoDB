#pragma once

#include <Godot.hpp>
#include <Node.hpp>

#include <cstdint>
#include <iostream>
#include <vector>
#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/stdx.hpp>
#include <mongocxx/uri.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/builder/stream/helpers.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include <bsoncxx/builder/stream/array.hpp>
#include <boost/optional/optional_io.hpp>


using bsoncxx::builder::stream::close_array;
using bsoncxx::builder::stream::close_document;
using bsoncxx::builder::stream::document;
using bsoncxx::builder::stream::finalize;
using bsoncxx::builder::stream::open_array;
using bsoncxx::builder::stream::open_document;

namespace godot
{
	class MongoDB : public Node
	{

		// Godot structure
	private:
		GODOT_CLASS(MongoDB, Node)
	public:
		static void _register_methods();
		void _init();
		void _process(float delta);

		MongoDB();
		~MongoDB();
	
		// Variables
	public:
		mongocxx::client* _client;
		mongocxx::database db;
		mongocxx::collection coll;

		// Gameplay methods
	public:
		void Register(String name, String passord);
		int Login(String name, String password);

	};
}
