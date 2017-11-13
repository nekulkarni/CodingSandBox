#!/usr/bin/env python

import boto3
import time
from threading import Thread

num_total_messages = 20


def produce():
    sqs = boto3.resource('sqs')
    queue = sqs.get_queue_by_name(QueueName='example-queue')

    for i in range(0, num_total_messages):
        response = queue.send_message(MessageBody='{}'.format(i))
        print("message sent", i)


def process():
    count = 0
    print("Started worker_thread")
    sqs = boto3.resource('sqs')
    queue = sqs.get_queue_by_name(QueueName='example-queue')

    while True:
        for message in queue.receive_messages():
            print('Message Received and processed: {0}'.format(message.body))
            message.delete()  # Let the queue know that the message is processed
            count += 1
        if count >= num_total_messages:
            break


def main():
    producer_thread = Thread(target=produce)
    worker_thread = Thread(target=process)

    producer_thread.start()
    worker_thread.start()

    producer_thread.join()
    worker_thread.join()


if __name__ == "__main__":
    main()