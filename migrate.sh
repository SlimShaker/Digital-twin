#!/bin/bash
mosquitto_sub -h 192.168.1.217 -t "system/migrate" | while read line; do
    parsed=$(echo "$line" | python3 -c "import sys,json; d=json.load(sys.stdin); print(d['target'],d['role'])")
    node=$(echo $parsed | awk '{print $1}')
    role=$(echo $parsed | awk '{print $2}')
    echo "migrating twin to $node with role=$role"
    docker service update \
        --constraint-rm 'node.hostname==Ehome' \
        --constraint-rm 'node.hostname==Emob' \
        --constraint-rm 'node.hostname==Ework' \
        --constraint-add "node.hostname==$node" \
        --env-rm NODE_ROLE \
        --env-add "NODE_ROLE=$role" \
        twin
    sleep 30
done