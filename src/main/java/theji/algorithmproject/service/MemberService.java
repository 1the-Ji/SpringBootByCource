package theji.algorithmproject.service;

import theji.algorithmproject.Member.Member;
import theji.algorithmproject.repository.MemberRepository;
import theji.algorithmproject.repository.MemoryMemberRepository;

import java.util.List;
import java.util.Optional;

public class MemberService {

    private final MemberRepository memberRepository;

    public MemberService(MemberRepository memberRepository) {
        this.memberRepository = memberRepository;
    }

    /**
     * 회원가입
     */
    public Long join(Member member) {
        validateionDuplicateMember(member);
        memberRepository.save(member);
        return member.getId();

    }

    private void validateionDuplicateMember(Member member) {
        memberRepository.findByName(member.getName()).ifPresent(m -> {
            throw new IllegalStateException("존재회원입니다.");
        });
    }
    /**
     *전체 회원 조회
     */
    public List<Member> findMembers() {
        return memberRepository.findAll();
    }
    public Optional<Member> findOne(Long memberId) {
        return memberRepository.findById(memberId);
    }
}

