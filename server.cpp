#include "httplib.h"
#include "AIAgent.h"

int main(void) {
    httplib::Server svr;
    AIAgent agent;

    svr.Post("/process", [&](const httplib::Request &req, httplib::Response &res) {
        std::string response = agent.process(req.body);
        res.set_content(response, "text/plain");
    });

    svr.listen("0.0.0.0", 8080);
}
