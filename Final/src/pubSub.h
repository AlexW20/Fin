#ifndef PUBSUB_H
#define PUBSUB_H

#include <map>
#include <vector>
#include <string>

using namespace std;

class Subscriber
{
public:
	virtual void receiveMessage(string channel, string message, void* data) = 0;
};

class PubSub
{
private:
	static map<string, vector<Subscriber*>> subscribers;

public:
	static void subscribe(string channel, Subscriber* subscriber);
	static void unsubscribe(string channel, Subscriber* subscriber);
	static void publish(string channel, string message, void* data);
};

#endif