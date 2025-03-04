#include <viam/sdk/components/board/server.hpp>

#include <viam/sdk/common/utils.hpp>
#include <viam/sdk/components/board/board.hpp>
#include <viam/sdk/config/resource.hpp>
#include <viam/sdk/resource/resource_manager.hpp>
#include <viam/sdk/rpc/server.hpp>

namespace viam {
namespace sdk {

BoardServer::BoardServer() : ResourceServer(std::make_shared<ResourceManager>()){};
BoardServer::BoardServer(std::shared_ptr<ResourceManager> manager) : ResourceServer(manager){};

::grpc::Status BoardServer::Status(::grpc::ServerContext* context,
                                   const ::viam::component::board::v1::StatusRequest* request,
                                   ::viam::component::board::v1::StatusResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::Status] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    const viam::common::v1::BoardStatus status = Board::to_proto(board->get_status(extra));

    *response->mutable_status() = status;

    return ::grpc::Status();
}

::grpc::Status BoardServer::SetGPIO(::grpc::ServerContext* context,
                                    const ::viam::component::board::v1::SetGPIORequest* request,
                                    ::viam::component::board::v1::SetGPIOResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::SetGPIO] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    board->set_gpio(request->pin(), request->high(), extra);

    return ::grpc::Status();
}

::grpc::Status BoardServer::GetGPIO(::grpc::ServerContext* context,
                                    const ::viam::component::board::v1::GetGPIORequest* request,
                                    ::viam::component::board::v1::GetGPIOResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::GetGPIO] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    response->set_high(board->get_gpio(request->pin(), extra));

    return ::grpc::Status();
}

::grpc::Status BoardServer::PWM(::grpc::ServerContext* context,
                                const ::viam::component::board::v1::PWMRequest* request,
                                ::viam::component::board::v1::PWMResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::PWM] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    response->set_duty_cycle_pct(board->get_pwm_duty_cycle(request->pin(), extra));

    return ::grpc::Status();
}

::grpc::Status BoardServer::SetPWM(::grpc::ServerContext* context,
                                   const ::viam::component::board::v1::SetPWMRequest* request,
                                   ::viam::component::board::v1::SetPWMResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::SetPWM] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    board->set_pwm_duty_cycle(request->pin(), request->duty_cycle_pct(), extra);

    return ::grpc::Status();
}

::grpc::Status BoardServer::PWMFrequency(
    ::grpc::ServerContext* context,
    const ::viam::component::board::v1::PWMFrequencyRequest* request,
    ::viam::component::board::v1::PWMFrequencyResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::PWMFrequency] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    const uint64_t result = board->get_pwm_frequency(request->pin(), extra);
    response->set_frequency_hz(result);

    return ::grpc::Status();
}

::grpc::Status BoardServer::SetPWMFrequency(
    ::grpc::ServerContext* context,
    const ::viam::component::board::v1::SetPWMFrequencyRequest* request,
    ::viam::component::board::v1::SetPWMFrequencyResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::SetPWMFrequency] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    board->set_pwm_frequency(request->pin(), request->frequency_hz(), extra);

    return ::grpc::Status();
}

::grpc::Status BoardServer::DoCommand(grpc::ServerContext* context,
                                      const viam::common::v1::DoCommandRequest* request,
                                      viam::common::v1::DoCommandResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::DoCommand] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);
    const AttributeMap result = board->do_command(struct_to_map(request->command()));

    *response->mutable_result() = map_to_struct(result);

    return ::grpc::Status();
}

::grpc::Status BoardServer::ReadAnalogReader(
    ::grpc::ServerContext* context,
    const ::viam::component::board::v1::ReadAnalogReaderRequest* request,
    ::viam::component::board::v1::ReadAnalogReaderResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::ReadAnalogReader] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->board_name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->board_name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    const Board::analog_value result = board->read_analog(request->analog_reader_name(), extra);
    response->set_value(result);

    return ::grpc::Status();
}

::grpc::Status BoardServer::GetDigitalInterruptValue(
    ::grpc::ServerContext* context,
    const ::viam::component::board::v1::GetDigitalInterruptValueRequest* request,
    ::viam::component::board::v1::GetDigitalInterruptValueResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::GetDigitalInterruptValue] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->board_name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->board_name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    const Board::digital_value result =
        board->read_digital_interrupt(request->digital_interrupt_name(), extra);
    response->set_value(result);

    return ::grpc::Status();
}

::grpc::Status BoardServer::SetPowerMode(
    ::grpc::ServerContext* context,
    const ::viam::component::board::v1::SetPowerModeRequest* request,
    ::viam::component::board::v1::SetPowerModeResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [Board::SetPowerMode] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    if (request->has_duration()) {
        auto duration = ::viam::sdk::from_proto(request->duration());
        board->set_power_mode(Board::from_proto(request->power_mode()), extra, duration);
    } else {
        board->set_power_mode(Board::from_proto(request->power_mode()), extra);
    }

    return ::grpc::Status();
}

::grpc::Status BoardServer::GetGeometries(::grpc::ServerContext* context,
                                          const ::viam::common::v1::GetGeometriesRequest* request,
                                          ::viam::common::v1::GetGeometriesResponse* response) {
    if (!request) {
        return ::grpc::Status(::grpc::StatusCode::INVALID_ARGUMENT,
                              "Called [GetGeometries] without a request");
    };

    const std::shared_ptr<Resource> rb = resource_manager()->resource(request->name());
    if (!rb) {
        return grpc::Status(grpc::UNKNOWN, "resource not found: " + request->name());
    }

    AttributeMap extra;
    if (request->has_extra()) {
        extra = struct_to_map(request->extra());
    }

    const std::shared_ptr<Board> board = std::dynamic_pointer_cast<Board>(rb);
    const std::vector<GeometryConfig> geometries = board->get_geometries(extra);
    for (const auto& geometry : geometries) {
        *response->mutable_geometries()->Add() = geometry.to_proto();
    }

    return ::grpc::Status();
}

void BoardServer::register_server(std::shared_ptr<Server> server) {
    server->register_service(this);
}

}  // namespace sdk
}  // namespace viam
