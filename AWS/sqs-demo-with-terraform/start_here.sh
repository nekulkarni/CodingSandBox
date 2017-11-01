#!/bin/bash
##
## wrapper for everything
##

set -e

terraform init
terraform plan
terraform apply

python send-and-receive-messages.py

terraform plan -destroy
terraform destroy

set +e

