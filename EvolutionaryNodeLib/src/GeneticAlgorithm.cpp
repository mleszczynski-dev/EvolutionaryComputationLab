#include "GeneticAlgorithm.h"

#include <asio/io_context.hpp>
#include <asio/post.hpp>

void GeneticAlgorithm::run()
{
	asio::io_context context;

	asio::post(context, [] {});

	context.run();
}
