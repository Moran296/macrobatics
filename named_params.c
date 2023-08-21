typedef struct
{
    int port;
    const char *host;
    int timeout;
} connection_params_t;

void connect(connection_params_t params)
{
    // do something!!
}

// just like in python, we can use named parameters
// #define CONNECT(...) connect((connection_params_t){__VA_ARGS__})

// but we can also set default values!
// #define CONNECT(...) connect((connection_params_t){.host = "google", __VA_ARGS__})

int main()
{

    connect((connection_params_t){
        .port = 1034,
        .host = "somehost",
        .timeout = 50,
    });

    // CONNECT(.port = 1034, .timeout = 50);

    // overriding default values means that we define this value twice, but it's ok!!
    // CONNECT(.port = 1034, .timeout = 50, .host = "somehost");
}
