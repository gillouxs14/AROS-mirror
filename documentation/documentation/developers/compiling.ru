=====================================
�������������� AROS �� ��������� ����
=====================================

:������:    + Flavio Stanchina
            + Henning Kiel
            + Bernardo Innocenti
            + Lennard voor den Dag
            + Aaron Digulla
            + Adam Chodorowski
:Copyright: Copyright (C) 2001-2008, The AROS Development Team
:������:    $Revision$
:����:      $Date$
:������:    ���������.
:��������: 
    ���� �������� ��������� ������� �������������� AROS. ���������� AROS 
    � ������� ��������� ���������� �� � ����� ����� AROS, � ������, �� �� 
    ������� �������������� AROS �� AROS. ��� �������������� � ���������� AROS 
    ��� ����������� Linux ��� FreeBSD.


.. ����������::


����������
==========

��� ������ AROS ����������� ��������� ����������� �����������:

+ GCC 3.2.2+
+ GNU Binutils
+ GNU Make
+ GNU AWK (GAWK) - ������ ������������� AWK ���� ����� �������
+ Python 2.2.1+
+ Bison
+ Flex
+ pngtopnm � ppmtoilbm (����� ������ netpbm)
+ Autoconf
+ Automake
+ ������� ������ ���������� cp, mv, sort, uniq, head, ...

��� ���������� ��� ��������� i386-linux ��� i386-freebsd, ����� �����������:

+ ��������� � ���������� X11 ��� ����������


�������� ���
============
            
�� ������ ������� �������� ��� AROS ��� �� �������� ��������__ ��� ��������� 
SVN (��� ����� ����������� `�������� ������`__ � �����������). ��� ������������ 
���������� �������� �� ����������� ����� ``source``, ����� ���� ������, ����� �� 
����� �������� �������������� ������������� ���������. � ��������� ������, 
�������� ������������ �� `������ � Subversion`__.

__ ../../download
__ ../../documentation/developers/contribute#the-subversion-repository
__ ../../documentation/developers/svn


������
======

����������������
----------------

� ������ ������� ��������� ������ ���������������� � �������� ���������� � 
��������� ������ AROS::

    > cd AROS
    > ./configure

�� ������ ������ ��������� ����� ��� ����������������. ��������� ����� �������� 
��� ���� �����:

``--enable-debug=LIST [default: none]``
    �������� ��������� ���� �������. ������� ��� ������� ����� �������������� 
    ��� ���������� ��������� � ������. ���� ������ �� ������������, �� 
    ����������� �������� ``all``. ���� ����� ``--enable-debug`` ������ �� 
    ������, �� �� ��������� ����������� �������� ``none``. ��������� ��������:
    
   ``none``
       ��������� ��� ���� ������� � ������� � �����.
   
   ``all``
       �������� ��� ����������������� ���� �������.
   
   ``stack``
       �������� ������� �����.

    ``mungwall``
        �������� ������������ ������ � ������� mungwall.
        
    ``modules``
        �������� ������� �������.

        
Hosted-������ AROS/i386-linux ��� AROS/i386-freebsd
"""""""""""""""""""""""""""""""""""""""""""""""""""

��� �� ���� �������� ����� ``--target`` ��� ������ ���� ������. ��� ������ 
hosted-������ �������� ��������� �����:

``--with-resolution=WIDTHxHEIGHTxDEPTH [default: 800x600x8]``
    ������ ���������� � ������� �����, ������� AROS ����� ������������ �� 
    ���������.

``--enable-xshm-extension [default: enabled]``
    �������� ������������� ���������� X11 MIT-SHM, ��� ��� ������������ 
    ���������� ������������������, �� ��� ���� ����� �� ����� ������ �������� 
    ��������� ��������������.
    
�� �� ������ ������������������ ��� ������.


Native-������ AROS/i386-pc
""""""""""""""""""""""""""

��� ������ ������������� ������ ��� i386-pc ��� ���� ������ ��� ���������������� 
����� ``--target=pc-i386``. ������������� �������� ��������� ����������� ��� 
i386-pc �����:

``--with-serial-debug=N [default: disabled]``
    �������� ����� ���������� ���������� �� ���������������� ���� ``N``.

�� �� ������ ������������������ ��� ������.    


��������������
--------------

��� ������� �������� ����������, ������ ��������� �������::

    > make

���� ������� �� ��������� ���� ����� ����, ��� �� �������� ��������� �� 
SVN-�����������, �� ���������� ���������::

    > make clean
    > rm -rf bin/
    > ./configure {options}
    > make

���� �� ����������� FreeBSD ��� �����-������ ������ ������������ �������, �� 
������������ GNU make � �������� ��������� ������� make, �� ��� ������� 
�������� � �������� GNU make, ��� ���������� ������������� ��������. ��������, 
�� FreeBSD ����� ��������� ������������� ������ GNU make, ���� ��������� 
�������::

    > gmake

 
Hosted-������ AROS/i386-linux ��� AROS/i386-freebsd
"""""""""""""""""""""""""""""""""""""""""""""""""""

���� �� ��������� �� ���������� hosted-������ i386-linux ��� i386-freebsd, �� 
��� ������� ������������� ����� ��������� ��������� ������� ��� ���������� 
��������� ��������� ����������::

    > make default-x11keymaptable


Native-������ AROS/i386-pc
""""""""""""""""""""""""""

���� �� ��������� �� ���������� native-������ i386-pc, �� ����� ���������� 
�������������� � ���� ``bin/pc-i386/gen/rom/boot/aros.bin`` ����� ������� ����� 
����������� �������. � ������� � ����� �� ������ ������� ����������� ISO-�����, 
�������� �������::

    > make bootiso-pc-i386

��������� ISO-����� ����� ������� � ``distfiles/aros-pc-i386.iso``.

          
����������
==========

������ ���������� ����� �� ������ � ���� �� ��������� ����
----------------------------------------------------------

���� �� ������������� �������������� ��������� ��������� ����� �� ������ � ���� 
�� ��������� ����, �� � ������ ������� ��� ���� ���������� �������� �� ��������� 
��� ������ ����, ������� �� ������������. �� ������ �������� ���� ��� 
���������� � ����� �����, ����� ���������. ��������� ���� � ��������� 
����������� �������� ����� �� ���������.

��� ������ ������������ ���� ��� ������, ������ ��������� ������� make, 
��� �������� ����::

    > AROS_TARGET_ARCH=$ARCH AROS_TARGET_CPU=$CPU make

����� ``$ARCH`` �������� ������������ �����������, ��� ������� ����� 
������������� ��������������, � ``$CPU`` - ��� ����������. ��������, ��� ������ 
AROS/i386-pc �� ������ ��������� ��������� �������::

    > AROS_TARGET_ARCH=pc AROS_TARGET_CPU=i386 make

���� �� ������������ ��������� ����� ��� ���� ��� ����������, �� ������ ������ 
������ �������� ``AROS_TARGET_ARCH``, �� ������� ��� ����������.

����� ���� ��� �� ���� ��� ������� make, ��������� �������������� �������, � 
����� ����� � ����������� ��������� ��������� ���������, ������� �� ������ 
�������� � ����� ��� ���������������� �������, �� ����� ������������ ������� 
���������� ���������, ��������� ������� make <���-������>-quick.

��� �������������� AROS
-----------------------

����  ��������� ����������� ���������, ��� ����������� ����� ���������� � 
�������������� AROS � Ubuntu Linux 6.10 "Edgy Eft". ��������, � ��� ��� ���� 
ISO-����� �������-����� � ����� Ubuntu � �� ���������� � ���� �������. ����� 
��� ������� ��������� � ��� ����������� � ���������.

��������� ����������� �������
"""""""""""""""""""""""""""""

��� ��� �� Live CD ����������� ����������� ������, ��� ���� �������� �� �� 
���������::

    > sudo apt-get install subversion gcc-3.4 gawk bison flex netpbm autoconf automake1.4 libx11-dev

��� ����������� ������ � ��������� ������ ������ ��� ������ �������� � Ubuntu.

��������� ISO8859 � �������� ��������� 
""""""""""""""""""""""""""""""""""""""

��� ����������� ���������� ��������� ��� ������������� ���������� AROS � �� 
����������. ������ ������� ������ � �������� ``en_US iso 8859-1`` � ������,
��������������� ���������� ���������::

     > sudo apt-get install localeconf
     > sudo dpkg-reconfigure localeconf
     
����������: ������� ������������, ��������, ����� ������������ ��������� KOI-8R
(�� �� UTF-8!).

����� ����� �� ������������� ��������� ��� ��������� ������::

     > sudo locale-gen "en_US"
     > sudo dpkg-reconfigure locales
     > export LANG="en_US.ISO-8859-1" 

��������� make 3.80
"""""""""""""""""""

��� ��������� ����������� ��� ������ ������� make, ���� �������� �������������� 
����������� Ubuntu. ��������� �������� ��������� ������ � �������� � ��������� 
��������� (nano) ������ ������������ ��������::

     > sudo nano /etc/apt/sources.list

�������� ���� ��������� ������::

    deb http://us.archive.ubuntu.com/ubuntu breezy main restricted
    deb http://us.archive.ubuntu.com/ubuntu dapper main restricted 

��������� �������� ��������� � ������� �� nano �������� Ctrl+X.

������ ������� ������ ���������� ��������::

     > sudo apt-get update

����� ����� ������������ �������� ������� Synaptic. ��������� ��� �� ����::

    System > Administration > Synaptic package manager

���, � ���������������� ������::

    ������� > ����������������� > �������� ������� Synaptic

����� ����� ������� � ��� ����� make, �������� "make" � ������ ���� �, ����� 
''package > force version..'', ������� ������ "3.80 (breezy)".


��������� �������� �����
""""""""""""""""""""""""

������� ���������� ���������� �� ������ � SVN-������������ ����� ����� �� 
�������� `������ � SVN <svn.php>`__

�������, �������, ������� �� ������ ������������ ����� ������ �� ���::

   > svn checkout https://svn.aros.org/svn/aros/trunk/AROS
   > cd AROS
   > svn checkout https://svn.aros.org/svn/aros/trunk/contrib


��������� � �������������� AROS �� ��������� ���� 
"""""""""""""""""""""""""""""""""""""""""""""""""

��-������, ���������� ��������� � ���������::

      > export CC="gcc-3.4"
      > ./configure

��� ����� ������������ ������������� �������� ��������� ������, ���� ��������� 
�������� � ������������ C.

� �����, �������::

      > make

��� ����� �����-�� ����� (�� ���������� ����� �� ��������� �����������). ����� 
����� � ��� ����� ���������������� hosted-������ AROS. �� �������� �����, ��� 
��� ����� ������������ ���������� � ���������� � �������� �������������� ��� 
���������� ��������� ������ ���������� EUAE.
