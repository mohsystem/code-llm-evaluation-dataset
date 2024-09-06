
#include <iostream>
#include <string>
#include <grpcpp/grpcpp.h>
#include "remote_object.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

class RemoteObjectServiceImpl final : public RemoteObject::Service {
public:
    Status GetValue(ServerContext* context, const Empty* request, Value* reply) override {
        reply->set_value(value_);
        return Status::OK;
    }

    Status SetValue(ServerContext* context, const Value* request, Empty* reply) override {
        value_ = request->value();
        return Status::OK;
    }

    Status Increment(ServerContext* context, const Empty* request, Empty* reply) override {
        value_++;
        return Status::OK;
    }

private:
    int value_ = 0;
};

void RunServer() {
    std::string server_address("0.0.0.0:50051");
    RemoteObjectServiceImpl service;

    ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << std::endl;
    server->Wait();
}

int main(int argc, char** argv) {
    RunServer();
    return 0;
}
