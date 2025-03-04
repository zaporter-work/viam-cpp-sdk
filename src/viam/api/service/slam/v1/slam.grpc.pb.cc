// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: service/slam/v1/slam.proto

#include "service/slam/v1/slam.pb.h"
#include "service/slam/v1/slam.grpc.pb.h"

#include <functional>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/impl/channel_interface.h>
#include <grpcpp/impl/client_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/rpc_service_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/sync_stream.h>
namespace viam {
namespace service {
namespace slam {
namespace v1 {

static const char* SLAMService_method_names[] = {
  "/viam.service.slam.v1.SLAMService/GetPosition",
  "/viam.service.slam.v1.SLAMService/GetPointCloudMap",
  "/viam.service.slam.v1.SLAMService/GetInternalState",
  "/viam.service.slam.v1.SLAMService/GetLatestMapInfo",
  "/viam.service.slam.v1.SLAMService/DoCommand",
};

std::unique_ptr< SLAMService::Stub> SLAMService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< SLAMService::Stub> stub(new SLAMService::Stub(channel, options));
  return stub;
}

SLAMService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetPosition_(SLAMService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_GetPointCloudMap_(SLAMService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_GetInternalState_(SLAMService_method_names[2], options.suffix_for_stats(),::grpc::internal::RpcMethod::SERVER_STREAMING, channel)
  , rpcmethod_GetLatestMapInfo_(SLAMService_method_names[3], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_DoCommand_(SLAMService_method_names[4], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status SLAMService::Stub::GetPosition(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPositionRequest& request, ::viam::service::slam::v1::GetPositionResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::viam::service::slam::v1::GetPositionRequest, ::viam::service::slam::v1::GetPositionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetPosition_, context, request, response);
}

void SLAMService::Stub::async::GetPosition(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPositionRequest* request, ::viam::service::slam::v1::GetPositionResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::viam::service::slam::v1::GetPositionRequest, ::viam::service::slam::v1::GetPositionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPosition_, context, request, response, std::move(f));
}

void SLAMService::Stub::async::GetPosition(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPositionRequest* request, ::viam::service::slam::v1::GetPositionResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetPosition_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::viam::service::slam::v1::GetPositionResponse>* SLAMService::Stub::PrepareAsyncGetPositionRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPositionRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::viam::service::slam::v1::GetPositionResponse, ::viam::service::slam::v1::GetPositionRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetPosition_, context, request);
}

::grpc::ClientAsyncResponseReader< ::viam::service::slam::v1::GetPositionResponse>* SLAMService::Stub::AsyncGetPositionRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPositionRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetPositionRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::ClientReader< ::viam::service::slam::v1::GetPointCloudMapResponse>* SLAMService::Stub::GetPointCloudMapRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPointCloudMapRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::viam::service::slam::v1::GetPointCloudMapResponse>::Create(channel_.get(), rpcmethod_GetPointCloudMap_, context, request);
}

void SLAMService::Stub::async::GetPointCloudMap(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPointCloudMapRequest* request, ::grpc::ClientReadReactor< ::viam::service::slam::v1::GetPointCloudMapResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::viam::service::slam::v1::GetPointCloudMapResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetPointCloudMap_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::viam::service::slam::v1::GetPointCloudMapResponse>* SLAMService::Stub::AsyncGetPointCloudMapRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPointCloudMapRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::viam::service::slam::v1::GetPointCloudMapResponse>::Create(channel_.get(), cq, rpcmethod_GetPointCloudMap_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::viam::service::slam::v1::GetPointCloudMapResponse>* SLAMService::Stub::PrepareAsyncGetPointCloudMapRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetPointCloudMapRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::viam::service::slam::v1::GetPointCloudMapResponse>::Create(channel_.get(), cq, rpcmethod_GetPointCloudMap_, context, request, false, nullptr);
}

::grpc::ClientReader< ::viam::service::slam::v1::GetInternalStateResponse>* SLAMService::Stub::GetInternalStateRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetInternalStateRequest& request) {
  return ::grpc::internal::ClientReaderFactory< ::viam::service::slam::v1::GetInternalStateResponse>::Create(channel_.get(), rpcmethod_GetInternalState_, context, request);
}

void SLAMService::Stub::async::GetInternalState(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetInternalStateRequest* request, ::grpc::ClientReadReactor< ::viam::service::slam::v1::GetInternalStateResponse>* reactor) {
  ::grpc::internal::ClientCallbackReaderFactory< ::viam::service::slam::v1::GetInternalStateResponse>::Create(stub_->channel_.get(), stub_->rpcmethod_GetInternalState_, context, request, reactor);
}

::grpc::ClientAsyncReader< ::viam::service::slam::v1::GetInternalStateResponse>* SLAMService::Stub::AsyncGetInternalStateRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetInternalStateRequest& request, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::viam::service::slam::v1::GetInternalStateResponse>::Create(channel_.get(), cq, rpcmethod_GetInternalState_, context, request, true, tag);
}

::grpc::ClientAsyncReader< ::viam::service::slam::v1::GetInternalStateResponse>* SLAMService::Stub::PrepareAsyncGetInternalStateRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetInternalStateRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderFactory< ::viam::service::slam::v1::GetInternalStateResponse>::Create(channel_.get(), cq, rpcmethod_GetInternalState_, context, request, false, nullptr);
}

::grpc::Status SLAMService::Stub::GetLatestMapInfo(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest& request, ::viam::service::slam::v1::GetLatestMapInfoResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::viam::service::slam::v1::GetLatestMapInfoRequest, ::viam::service::slam::v1::GetLatestMapInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetLatestMapInfo_, context, request, response);
}

void SLAMService::Stub::async::GetLatestMapInfo(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest* request, ::viam::service::slam::v1::GetLatestMapInfoResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::viam::service::slam::v1::GetLatestMapInfoRequest, ::viam::service::slam::v1::GetLatestMapInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetLatestMapInfo_, context, request, response, std::move(f));
}

void SLAMService::Stub::async::GetLatestMapInfo(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest* request, ::viam::service::slam::v1::GetLatestMapInfoResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetLatestMapInfo_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::viam::service::slam::v1::GetLatestMapInfoResponse>* SLAMService::Stub::PrepareAsyncGetLatestMapInfoRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::viam::service::slam::v1::GetLatestMapInfoResponse, ::viam::service::slam::v1::GetLatestMapInfoRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetLatestMapInfo_, context, request);
}

::grpc::ClientAsyncResponseReader< ::viam::service::slam::v1::GetLatestMapInfoResponse>* SLAMService::Stub::AsyncGetLatestMapInfoRaw(::grpc::ClientContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetLatestMapInfoRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status SLAMService::Stub::DoCommand(::grpc::ClientContext* context, const ::viam::common::v1::DoCommandRequest& request, ::viam::common::v1::DoCommandResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::viam::common::v1::DoCommandRequest, ::viam::common::v1::DoCommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_DoCommand_, context, request, response);
}

void SLAMService::Stub::async::DoCommand(::grpc::ClientContext* context, const ::viam::common::v1::DoCommandRequest* request, ::viam::common::v1::DoCommandResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::viam::common::v1::DoCommandRequest, ::viam::common::v1::DoCommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DoCommand_, context, request, response, std::move(f));
}

void SLAMService::Stub::async::DoCommand(::grpc::ClientContext* context, const ::viam::common::v1::DoCommandRequest* request, ::viam::common::v1::DoCommandResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_DoCommand_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::viam::common::v1::DoCommandResponse>* SLAMService::Stub::PrepareAsyncDoCommandRaw(::grpc::ClientContext* context, const ::viam::common::v1::DoCommandRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::viam::common::v1::DoCommandResponse, ::viam::common::v1::DoCommandRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_DoCommand_, context, request);
}

::grpc::ClientAsyncResponseReader< ::viam::common::v1::DoCommandResponse>* SLAMService::Stub::AsyncDoCommandRaw(::grpc::ClientContext* context, const ::viam::common::v1::DoCommandRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncDoCommandRaw(context, request, cq);
  result->StartCall();
  return result;
}

SLAMService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SLAMService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SLAMService::Service, ::viam::service::slam::v1::GetPositionRequest, ::viam::service::slam::v1::GetPositionResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SLAMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::service::slam::v1::GetPositionRequest* req,
             ::viam::service::slam::v1::GetPositionResponse* resp) {
               return service->GetPosition(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SLAMService_method_names[1],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< SLAMService::Service, ::viam::service::slam::v1::GetPointCloudMapRequest, ::viam::service::slam::v1::GetPointCloudMapResponse>(
          [](SLAMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::service::slam::v1::GetPointCloudMapRequest* req,
             ::grpc::ServerWriter<::viam::service::slam::v1::GetPointCloudMapResponse>* writer) {
               return service->GetPointCloudMap(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SLAMService_method_names[2],
      ::grpc::internal::RpcMethod::SERVER_STREAMING,
      new ::grpc::internal::ServerStreamingHandler< SLAMService::Service, ::viam::service::slam::v1::GetInternalStateRequest, ::viam::service::slam::v1::GetInternalStateResponse>(
          [](SLAMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::service::slam::v1::GetInternalStateRequest* req,
             ::grpc::ServerWriter<::viam::service::slam::v1::GetInternalStateResponse>* writer) {
               return service->GetInternalState(ctx, req, writer);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SLAMService_method_names[3],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SLAMService::Service, ::viam::service::slam::v1::GetLatestMapInfoRequest, ::viam::service::slam::v1::GetLatestMapInfoResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SLAMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::service::slam::v1::GetLatestMapInfoRequest* req,
             ::viam::service::slam::v1::GetLatestMapInfoResponse* resp) {
               return service->GetLatestMapInfo(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      SLAMService_method_names[4],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< SLAMService::Service, ::viam::common::v1::DoCommandRequest, ::viam::common::v1::DoCommandResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](SLAMService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::viam::common::v1::DoCommandRequest* req,
             ::viam::common::v1::DoCommandResponse* resp) {
               return service->DoCommand(ctx, req, resp);
             }, this)));
}

SLAMService::Service::~Service() {
}

::grpc::Status SLAMService::Service::GetPosition(::grpc::ServerContext* context, const ::viam::service::slam::v1::GetPositionRequest* request, ::viam::service::slam::v1::GetPositionResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SLAMService::Service::GetPointCloudMap(::grpc::ServerContext* context, const ::viam::service::slam::v1::GetPointCloudMapRequest* request, ::grpc::ServerWriter< ::viam::service::slam::v1::GetPointCloudMapResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SLAMService::Service::GetInternalState(::grpc::ServerContext* context, const ::viam::service::slam::v1::GetInternalStateRequest* request, ::grpc::ServerWriter< ::viam::service::slam::v1::GetInternalStateResponse>* writer) {
  (void) context;
  (void) request;
  (void) writer;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SLAMService::Service::GetLatestMapInfo(::grpc::ServerContext* context, const ::viam::service::slam::v1::GetLatestMapInfoRequest* request, ::viam::service::slam::v1::GetLatestMapInfoResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status SLAMService::Service::DoCommand(::grpc::ServerContext* context, const ::viam::common::v1::DoCommandRequest* request, ::viam::common::v1::DoCommandResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace viam
}  // namespace service
}  // namespace slam
}  // namespace v1

