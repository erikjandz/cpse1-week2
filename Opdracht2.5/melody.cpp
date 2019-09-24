//Author is Erik de Zeeuw

#include "melody.hpp"

class meldody : public melody {
public:
	void play( note_player & p ){
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::D6,  note::dQ } );
		p.play( note{ note::C6,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::G6,  note::dQ } );
		p.play( note{ note::A6,  note::dQ } );
		p.play( note{ note::G5,  note::dQ } );
		p.play( note{ note::G6,  note::dQ } );
		p.play( note{ note::G6,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::D6,  note::dQ } );
		p.play( note{ note::C6,  note::dQ } );
		p.play( note{ note::A5,  note::dQ } );
		p.play( note{ note::G5,  note::dQ } );
		p.play( note{ note::E5,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::F5,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::D6,  note::dQ } );
		p.play( note{ note::E6,  note::dQ } );
		p.play( note{ note::D6,  note::dQ } );
		p.play( note{ note::D6,  note::dQ } );
		p.play( note{ note::C5,  note::dQ } );
	}
};