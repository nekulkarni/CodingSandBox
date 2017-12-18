#
# Ubuntu-based dockerfile to build scikit-learn programs
#

FROM ubuntu

RUN sudo apt-get update

RUN apt-get -y install \
	build-essential \
	python-dev \
	python-setuptools \
	python-pip

RUN apt-get -y install \
	python-numpy \
	python-scipy \
	libatlas-dev \
	libatlas3-base

RUN pip install Flask
RUN pip install flask-restful

RUN apt-get -y install python-sklearn