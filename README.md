# Distributed Systems
## Berkeley’s Algorithm
Berkeley’s Algorithm is a clock synchronization technique used in distributed systems.
Psuedocode:

```
// receiving time from all clients
repeat_for_all_clients {
 time_at_client_node = receive_time_at_client()
 // calculating time difference
 time_difference = time_at_master_node - time_at_clients_node
}

// average time difference calculation
average_time_difference = sum(all_time_differences) / number_of_clients

synchronized_time = current_master_time + average_time_difference

// broadcasting synchronized to whole network
broadcast_time_to_all_clients(synchronized_time)
```
