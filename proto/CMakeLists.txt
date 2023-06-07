find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)
find_package(Threads)

#
# Protobuf/Grpc source files
#
file(GLOB_RECURSE PROTO_FILES
    ${CMAKE_CURRENT_LIST_DIR}/*.proto
)

#
# Add Library target with protobuf sources
#
add_library(serviceproto ${PROTO_FILES})
target_link_libraries(serviceproto
    PUBLIC
        protobuf::libprotobuf
        gRPC::grpc
        gRPC::grpc++

        # reflection
        gRPC::grpc++_reflection
)

#
# Compile protobuf and grpc files in serviceproto target to cpp
#
get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET serviceproto LANGUAGE cpp)
protobuf_generate(TARGET serviceproto LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
