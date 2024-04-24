set(COMPONENT_SRCS
"main.cpp"
"ntp_client/NtpClient.cpp"   
"http_client/HttpClient.cpp"                 
)

set(COMPONENT_ADD_INCLUDEDIRS
"ntp_client"
"http_client"
)


register_component()

target_compile_options(${COMPONENT_LIB} PRIVATE 
)