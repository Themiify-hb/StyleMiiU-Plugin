#!/bin/bash

PLUGIN_NAME="time-sync"
IMAGE="${PLUGIN_NAME}-image"
CONTAINER="${PLUGIN_NAME}-container"


cleanup()
{
    echo "Cleaning up Docker..."
    docker container rm --force "$CONTAINER"
    docker image rm --force "$IMAGE"
    echo "You may also want to run 'docker system prune --force' to delete Docker's caches."
    exit $1
}
trap cleanup INT TERM


docker build --tag "$IMAGE" . || cleanup 1

ARGS="--tty --interactive --name $CONTAINER $IMAGE"
docker run $ARGS sh -c "make" || cleanup 2
echo "Compilation finished."

# Copy the wps file out.
docker cp "$CONTAINER:/project/stylemiiu.wps" .

cleanup 0
